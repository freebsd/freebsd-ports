/* siteexclude.c - check article id for excluded sites
 *
 * Copyright (C) 1995 Peter Fox <fox@roestock.demon.co.uk>
 *
 * This code may be freely copied in it's entirety, but the
 * above notice may not be removed or altered without
 * reference to the author.
 * Individuals may make changes for their own use, however
 * any changed copies may not be distributed without
 * reference to the author.
 * There isn't any guarantee of usefulness or efficacy for
 * any particular purpose. Take it as it is.
 */
#include <stdio.h>
#include <string.h>
#include "syslog.h"
#include "conf.h"

#ifdef TEST
#define SITEEXCLUDING
#endif /*TEST*/

#ifdef SITEEXCLUDING
typedef struct slist
{
	struct slist *next;
	char *str;
} SLIST, *SLISTPTR;

#define HASHSIZE 256
#define HASHFN(x) (((x[1] & 15) << 4)|(x[2] & 15)) /* x is (char *), skip '@' */

#ifdef TEST
#define SITEFILE "./sites"
#define DROPFILE "./dropped"
#define log_msg printf
#define log_sys printf
#define debug_flag 1
#else /*!TEST*/
extern int debug_flag;
#ifndef SITEFILE
#define SITEFILE "/var/lib/news/excludesites"
#endif /*SITEFILE*/
#ifndef DROPFILE
#define DROPFILE "/var/lib/news/droppedarticles"
#endif /*DROPFILE*/
#endif /*TEST*/

SLIST hash[HASHSIZE];

static FILE *dropfp = (FILE*)0;

site_init()
{
	int i;
	FILE *fp;
	char linbuf[BUFSIZ];
	SLISTPTR ptr;
	int entries, collisions;
	entries = 0;
	collisions = 0;
	for(i = 0; i < HASHSIZE; i++)
	{
		hash[i].next = (SLISTPTR)0;
		hash[i].str = (char *)0;
	}
	if(!(fp = fopen(SITEFILE, "r")))
	{
		log_msg("site_init: warning - no site exclude file %s", SITEFILE);
		return;
	}
	if(!(dropfp = fopen(DROPFILE, "a")))
	{
		log_msg("site_init: warning - cannot open file %s for append, dropped articles logged instead", DROPFILE);
	}
	else
		fprintf(dropfp, "-----\n");
	/* File contains lines with complete site names to exclude */
	/* We add the leading @ and trailing > */
	linbuf[0] = '@';
	while(1)
	{
        /* Read in a line */
        (void) fgets(linbuf+1, sizeof (linbuf)-2, fp);
        if(feof(fp))
			break;
        /* If a read error then report it and abort */
        if (ferror(fp))
		{
            log_sys("site_init: error reading %s", SITEFILE);
            break;
		}
		if(linbuf[1])
		{
			/* Kill the \n */
			linbuf[strlen(linbuf)-1] = '>';
			entries++;
			ptr = &hash[HASHFN(linbuf)];
			if(debug_flag)
				fprintf(stderr, "'%s: %08lx'\n", linbuf, ptr);
			if(!ptr->str)
				ptr->str = strdup(linbuf);
			else
			{
				/* Run along to the last in line */
				while(ptr->next)
					ptr = ptr->next;
				ptr->next = (SLISTPTR)malloc(sizeof(SLIST));
				ptr = ptr->next;
				ptr->next = (SLISTPTR)0;
				ptr->str = strdup(linbuf);
				collisions++;
			}
		}
	}
	fclose(fp);
	if(debug_flag)
		log_msg("site_init: site exclude file %s read: %d entries, %d collisions",
			SITEFILE, entries, collisions);
}

site_check(char *site)
{
	SLISTPTR ptr;
	ptr = &hash[HASHFN(site)];
	if(debug_flag)
		fprintf(stderr, " '%s: %08lx'", site, ptr);
	if(!ptr->str)
		return(0);
	while(ptr)
	{
		if(strcmp(site, ptr->str) == 0)
			return(1);
		ptr = ptr->next;
	}
	return(0);
}

site_droparticle(char *id)
{
	if(dropfp)
		fprintf(dropfp, "%s\n", id);
	else
		log_msg("Excluded article: %s", id);
}

site_close()
{
	if(dropfp)
		fclose(dropfp);
}

#ifdef TEST
main(int argc, char **argv)
{
	site_init();
	argv++;
	argc--;
	while(argc--)
	{
		if(site_check(*argv))
			printf("Found %s\n", *argv);
		argv++;
	}
	return(0);
}
#endif /*TEST*/
#endif /* SITEEXCLUDING */
