#!/bin/sh

USER=$1
UID=$2
MAILMANDIR=$3
GROUP=${USER}
GID=${UID}

if [ -z "$USER" -o -z "$UID" -o -z "$MAILMANDIR" ]; then
	echo "Syntax: $0 <username> <uid> <homedir>"
	exit 1
fi

if pw group show "${GROUP}" 2>/dev/null; then
	echo "You already have a group \"${GROUP}\", so I will use it."
else
	if pw groupadd ${GROUP} -g ${GID}; then
		echo "Added group \"${GROUP}\"."
	else
		echo "Adding group \"${GROUP}\" failed..."
		exit 1
	fi
fi

if pw user show "${USER}" 2>/dev/null; then
	echo "You already have a user \"${USER}\", so I will use it."
else
	if pw useradd ${USER} -u ${UID} -g ${GROUP} -h - \
		-d ${MAILMANDIR} -s /sbin/nologin -c "Mailman User"
	then
		echo "Added user \"${USER}\"."
	else
		echo "Adding user \"${USER}\" failed..."
		exit 1
	fi
fi
