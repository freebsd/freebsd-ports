#!/bin/sh
# $FreeBSD$

PATH=/bin:/usr/sbin:/usr/bin:/bin

make_user() {
	USER=$1
	UID=$2
	COMMENT="$3"
	USER_HOME=/nonexistent
	GROUP=${USER}
	if pw user show "${USER}" 2>/dev/null; then
		echo "You already have a user \"${USER}\", so I will use it."
	else
		while pw user show ${UID}; do
			UID=`expr ${UID} + 1`
		done
		GID=${UID}

		if pw groupadd ${GROUP} -g ${GID}; then
			echo "Added group \"${GROUP}\"."
		else
			echo "Adding group \"${GROUP}\" failed..."
			exit 1
		fi

		if pw useradd ${USER} -u ${UID} -g ${GROUP} -h - \
			-d ${USER_HOME} -s /sbin/nologin -c "${COMMENT}"
		then
			echo "Added user \"${USER}\"."
		else
			echo "Adding user \"${USER}\" failed..."
			exit 1
		fi
	fi
}

make_user clockspeed 801 "clockspeed adjust service"
make_user taiclock 802 "taiclockd daemon"
make_user log 803 "djb service log"
