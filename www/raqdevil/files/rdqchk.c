#include <sys/types.h>
#include <ufs/ufs/quota.h>

#include <err.h>

int
main (int argc, char **argv)
{
	int retval;
	struct dqblk dqb;

	retval = quotactl("/", QCMD(Q_GETQUOTA, USRQUOTA), 0, &dqb);
	if (retval != 0) {
		err(-1, "No user quotas in /");
	}

	retval = quotactl("/", QCMD(Q_GETQUOTA, GRPQUOTA), 0, &dqb);
	if (retval != 0) {
		err(-1, "No group quotas in /");
	}

	retval = quotactl("/home", QCMD(Q_GETQUOTA, USRQUOTA), 0, &dqb);
	if (retval != 0) {
		err(-1, "No user quotas in /home");
	}

	retval = quotactl("/home", QCMD(Q_GETQUOTA, GRPQUOTA), 0, &dqb);
	if (retval != 0) {
		err(-1, "No group quotas in /home");
	}

	return 0;
}
