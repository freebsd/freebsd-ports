#!/bin/sh
[ -x /usr/local/sbin/rtsp_proxy ] && /usr/local/sbin/rtsp_proxy > /dev/null & && echo $! > /var/run/rtsp_proxy.pid && echo -n ' rtsp_proxy'
