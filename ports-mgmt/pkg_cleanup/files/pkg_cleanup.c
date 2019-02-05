#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <ctype.h>
#include <curses.h>
#include <dialog.h>
#include <errno.h>
#include <glob.h>
#include <search.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringlist.h>
#include <sysexits.h>
#include <unistd.h>

static int		menulen=0;

typedef DIALOG_LISTITEM ListItem;
ListItem	*menu;
#define ITEM_DATA		help
#define ITEM_PROMPT		name
#define ITEM_CHECKED	state

static void
free_menu(void)
{
	int		i;

	if(menu) {
		for(i=0; i<menulen; i++) {
			if(menu[i].ITEM_DATA) {
				free(menu[i].ITEM_DATA);
				menu[i].ITEM_DATA=NULL;
			}
			if(menu[i].ITEM_PROMPT) {
				free(menu[i].ITEM_PROMPT);
				menu[i].ITEM_PROMPT=NULL;
			}
		}
		free(menu);
	}
	menu=NULL;
	menulen=0;
}

static int
blacklist(char *path, int operation)
{
	ENTRY		item;

	item.data=NULL;
	if (operation == ENTER)
		item.key=strdup(path);
	else
		item.key = path;

	return(hsearch(item, operation)!=NULL);
}

static char *
read_desc(char *path)
{
	char newpath[MAXPATHLEN+1];
	char *p=NULL;
	char *np=NULL;
	FILE *pkg;
	char chunk[1024];
	size_t	cs, len=0;

	sprintf(newpath,"/usr/sbin/pkg query %%e \"%s\"", path);
	fflush(stdout);
	pkg=popen(newpath, "r");
	if(!pkg)
		return NULL;
	while((cs=fread(chunk, 1, sizeof(chunk), pkg))) {
		np=(char *)realloc(p, len+cs+1);
		if(!np) {
			pclose(pkg);
			free(p);
			return NULL;
		}
		p=np;
		memcpy(p+len, chunk, cs);
		len+=cs;
		p[len]=0;
	}
	pclose(pkg);
	if(len==0) {
		free(p);
		return NULL;
	}
	return p;
}

/* Read +COMMENT, add to menu and blacklist */
static int
add_item(char *path, char *comment)
{
	char		*p;
	ListItem	*newmenu;

	if(blacklist(path,FIND))
		return(0);
	blacklist(path,ENTER);

	newmenu=(ListItem *)realloc(menu, sizeof(ListItem)*(menulen+1));
	if(newmenu==NULL)
		return(-1);
	menu=newmenu;

	p=strrchr(path,'/');
	if(p==NULL)
		p=path;
	else
		p++;

	menu[menulen].ITEM_PROMPT=strdup(p);
	menu[menulen].ITEM_CHECKED=0;
	menu[menulen].text="";

	menu[menulen].ITEM_DATA=strdup(comment);
	menulen++;

	return(0);
}

static void
do_init_dialog(void)
{
	init_dialog(stdin, stdout);
	dialog_state.use_shadow=FALSE;
}

static int
display_menu(void)
{
	int	ret=0;
	int	maxx,maxy;
	int	curr;

	do_init_dialog();
	getmaxyx(stdscr, maxy, maxx);
	dialog_vars.help_button=1;
	dialog_vars.item_help=1;
loop:
	switch(ret=dlg_checklist("Welcome to pkg_cleanup.", "These are the leaf packages installed on your system\nChose the packages to deinstall. Help will display the package description.", maxy-1, maxx, maxy-9, menulen, menu, " X", FLAG_CHECK, &curr)) {
		case DLG_EXIT_HELP: {
			char *p = read_desc(menu[curr].ITEM_PROMPT);
			if(p) {
				dialog_vars.help_button=0;
				dialog_msgbox(menu[curr].ITEM_DATA, p, maxy-4, maxx-4, TRUE);
				dialog_vars.help_button=1;
				free(p);
			}
			goto loop;
		}
		case 0:
			ret=0;
			break;
		default:
			ret=-1;
			break;
	}
	dialog_vars.help_button=0;
	dialog_vars.item_help=0;
	end_dialog();
	return(ret);
}

static int
remove_packages(void)
{
	char	**args;
	char	*env[1]={NULL};
	char	**p;
	int		i;
	int		delete_count=0;
	pid_t	child;
	int		status;
	size_t	st;

	args=(char **)malloc((menulen+4) * sizeof(char *));
	if(!args) {
		do_init_dialog();
		dialog_msgbox("ERROR", "Can not allocate memory for package list!", 5, 45, TRUE);
		end_dialog();
		return(-1);
	}
	p=args;
	*(p++)="/usr/sbin/pkg";
	*(p++)="delete";
	*(p++)="-y";
	for(i=0;i<menulen;i++) {
		if(menu[i].ITEM_CHECKED) {
			*(p++)=menu[i].ITEM_PROMPT;
			delete_count++;
		}
	}
	*(p)=NULL;
	if(!delete_count) {
		do_init_dialog();
		dialog_msgbox(NULL, "No packages selected", 5, 24, TRUE);
		end_dialog();
		free(args);
		return(-1);
	}
	/* Ensure stdio is "right" */
	if(!isendwin())
		endwin();
	child=vfork();
	if(child==0) {
		execve(args[0], args, env);
		fprintf(stderr,"ERROR: %d!\n",errno);
		_exit(EXIT_FAILURE);
	}
	free(args);
	if(child==-1) {
		do_init_dialog();
		dialog_msgbox(NULL, "Can not fork()", 5, 18, TRUE);
		end_dialog();
		return(-1);
	}
	waitpid(child, &status, 0);
	/* On an error return, pause */
	if(WIFSIGNALED(status) || (WIFEXITED(status) && WEXITSTATUS(status))) {
		fputs("\n\nPress ENTER to continue... ",stderr);
		fgetln(stdin, &st);
	}

	return(0);
}

/* Goes through the glob contents, looking for zero-length +REQUIRED-BY */
static int
read_pkglist(int loops)
{
	FILE	*pkg;
	char	line[1024];
	char	*p;

	do_init_dialog();
	dialog_msgbox(NULL, "Searching for leaves", 5, 23, FALSE);
	fflush(stdout);
	pkg=popen("/usr/sbin/pkg query -e \"%#r=0 && %k=0\" \"%n-%v\\t%c\"", "r");
	if(!pkg) {
		fputs("Error executing pkg.\n", stderr);
		return -1;
	}
	while(fgets(line, sizeof(line), pkg)!=NULL) {
		for(p=strchr(line, 0)-1; p>line && isspace(*p); p--)
			*p=0;
		p=strtok(line, "\t");
		p=strtok(NULL, "\0");
		add_item(line, p?p:"");
	}
	if(WEXITSTATUS(pclose(pkg)) && menulen==0) {
		fputs("pkg returned an error.\n", stderr);
		return -1;
	}
	dlg_clear();
	if(menulen==0) {
		if(loops)
			dialog_msgbox(NULL, "No new leaves found", 5, 23, TRUE);
		else
			dialog_msgbox(NULL, "No leaves found", 5, 19, TRUE);
		end_dialog();
		return(-1);
	}
	end_dialog();
	return(0);
}

static int
keep_going(void)
{
	int ret;

	do_init_dialog();
	ret = !dialog_yesno(NULL,"Do you want to process the new leaves packages?",-1,-1);
	end_dialog();
	return(ret);
}

/*
 * The hash table is to keep track of leaves which have already been displayed
 * to the user.
 */
int main(int argc, char **argv)
{
	int			i;

	/* Initialize space for blacklist hash table */
	if(hcreate(10000)==0) {
		fputs("Cannot create hash table.\n",stderr);
		return(EX_UNAVAILABLE);
	}

	i=0;
	do {
		if(read_pkglist(i++))
			break;
		if(display_menu())
			break;
		if(remove_packages())
			break;
		free_menu();
	} while(keep_going());
	hdestroy();

	fputs("\nProgram Terminated Successfully\n",stderr);
	return(0);
}
