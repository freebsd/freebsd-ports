#!/bin/sh
# $FreeBSD$
# * stolen from mailman port.

USER=$1
UID=$2
GROUP=${USER}
GID=${UID}

if [ -z "$USER" -o -z "$UID" ]; then
	echo "Syntax: $0 <username> <uid>"
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
		-d /notexistence -s /sbin/nologin -c "MoinMoin User"
	then
		echo "Added user \"${USER}\"."
	else
		echo "Adding user \"${USER}\" failed..."
		exit 1
	fi
fi
