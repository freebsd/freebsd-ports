#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

case "$1" in
start)
	( [ -x ${PREFIX}/sbin/amavisd ] || [ -x ${PREFIX}/sbin/amavis-milter ] ) || exit 1
	AMAVISD=$(/bin/ps -xU %%AMAVISUSER%% | grep amavisd | awk '{ print $1 }')
	AMAVIS_MILTER=$(/bin/ps -xU %%AMAVISUSER%% | grep amavis-milter | awk '{ print $1 }')
	( /bin/test "$AMAVISD" || /bin/test "$AMAVIS_MILTER" ) && \
	su - %%AMAVISUSER%% -c "/bin/kill $AMAVISD $AMAVIS_MILTER" > /dev/null
	rm -rf /var/amavis/amavis*.sock
	su - %%AMAVISUSER%% -c "${PREFIX}/sbin/amavis-milter -D -p /var/amavis/amavis-milter.sock" > /dev/null
	su - %%AMAVISUSER%% -c ${PREFIX}/sbin/amavisd > /dev/null 2>&1 && echo -n ' amavisd-milter'
	;;
stop)
	( [ -x ${PREFIX}/sbin/amavisd ] || [ -x ${PREFIX}/sbin/amavis-milter ] ) || exit 1
	AMAVISD=$(/bin/ps -xU %%AMAVISUSER%% | grep amavisd | awk '{ print $1 }')
	AMAVIS_MILTER=$(/bin/ps -xU %%AMAVISUSER%% | grep amavis-milter | awk '{ print $1 }')
	( /bin/test "$AMAVISD" || /bin/test "$AMAVIS_MILTER" ) && \
	su - %%AMAVISUSER%% -c "/bin/kill $AMAVISD $AMAVIS_MILTER" > /dev/null && echo -n ' amavisd-milter'
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	;;
esac

exit 0
