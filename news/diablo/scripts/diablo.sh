#!/bin/sh

if [ -x %%PREFIX%%/news/rc.news ] ; then
    %%PREFIX%%/news/rc.news && echo -n ' diablo'
fi
