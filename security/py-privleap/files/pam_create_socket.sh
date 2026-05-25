#!/bin/sh

if [ -n "${PAM_USER}" ] && [ ! -S "/var/run/privleapd/comm/${PAM_USER}" ]; then
    exec leapctl --create "${PAM_USER}"
    exit 1
fi

exit 0
