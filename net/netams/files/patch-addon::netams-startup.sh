*** addon/netams-startup.sh.orig      Sun Dec 15 14:42:13 2002
--- addon/netams-startup.sh      Mon Dec 16 17:07:08 2002
***************
5c5
< debug=1
---
> debug=0
7,8c7,8
< configfile=/home/anton/netams/netams.cfg
< appfile=/home/anton/netams/netams
---
> configfile=/usr/local/etc/netams.conf
> appfile=/usr/local/libexec/netams
10c10
< path=/tmp
---
> path=/var/log
87c87
<
---
>         sleep 3;

