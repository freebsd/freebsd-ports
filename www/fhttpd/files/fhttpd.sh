#!/bin/sh
[ -x /usr/local/sbin/fhttpd ] && /usr/local/sbin/fhttpd -c /usr/local/etc/fhttpd.conf -l /usr/local/share/fhttpd/fhttpd.log >/dev/null 2>&1 && echo -n " fhttpd"
