#!/bin/sh

LOG=/var/log/run-nrg.log

#renice 5 -p $$ >/dev/null 2>&1
/usr/local/nrg/run-nrg >$LOG
#/usr/local/nrg/run-nrg.local >>$LOG
