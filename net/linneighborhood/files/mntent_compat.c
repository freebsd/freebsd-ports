#include "mntent.h"
#include <sys/types.h>
#include <sys/wait.h>

char mntent_global_mnt_fsname[1024];
char mntent_global_mnt_dir[1024];
char mntent_global_mnt_type[1024];
char mntent_global_mnt_opts[1024];

struct mntent mntent_global_mntent;

FILE * setmntent(char * filep, char * type)
{
	char * tempFileName = tmpnam(0);
	FILE * tempFile = 0;
	char s[256];
	int i;

	sprintf(s, "mount -p > %s", tempFileName);
	i = system(s);
	if (i == 127 || i == -1 || !WIFEXITED(i) || WEXITSTATUS(i))
	{
		unlink(tempFileName);
		return 0;
	}
	tempFile = fopen(tempFileName, type);
	unlink(tempFileName);
	return tempFile;
}

struct mntent *getmntent(FILE * filep)
{
	char *p, c, tmp[32];
	int field = 0;
	mntent_global_mntent.mnt_fsname = mntent_global_mnt_fsname;
	mntent_global_mntent.mnt_dir = mntent_global_mnt_dir;
	mntent_global_mntent.mnt_type = mntent_global_mnt_type;
	mntent_global_mntent.mnt_opts = mntent_global_mnt_opts;
	mntent_global_mntent.mnt_freq = 0;
	mntent_global_mntent.mnt_passno = 0;
	*mntent_global_mnt_fsname = 0;
	*mntent_global_mnt_dir = 0;
	*mntent_global_mnt_type = 0;
	*mntent_global_mnt_opts = 0;
	
	if (feof(filep))
		return 0;
	p = mntent_global_mnt_fsname;
	while (!feof(filep))
	{
		c = fgetc(filep);
		if (c == ' ' || c == '\t' || c == '\n')
		{
			*p = 0;
			switch (field)
			{
				case 0:
				case 2:
				case 4:
				case 6:
					++field;
					break;
				case 8:
					mntent_global_mntent.mnt_freq = atoi(tmp);
					++field;
					break;
				case 10:
					mntent_global_mntent.mnt_passno = atoi(tmp);
					++field;
					break;
			}
			p = 0;
			if (c == '\n')
				return & mntent_global_mntent;
			continue;
		}
		if (!p)
		{
			switch (field)
			{
				case 1:
					p = mntent_global_mnt_dir;
					break;
				case 3:
					p = mntent_global_mnt_type;
					break;
				case 5:
					p = mntent_global_mnt_opts;
					break;
				case 7:
				case 9:
					p = tmp;
					break;
			}
			++field;
		}
		*p++ = c;
	}
	
	return 0;
}

//char * hasmntopt(struct mntent * mnt, char * opt);
int endmntent(FILE * filep)
{
	return fclose(filep);
}
