#!/bin/sh

if [ -x XXXX/sbin/nqsdaemon ] ; then
    XXXX/sbin/nqsdaemon > /var/log/nqs.log
    echo -n ' nqs' 
fi
