#!/bin/sh

exec %%PREFIX%%/AntiVir/antivir -C %%PREFIX%%/etc/antivir.conf --home-dir=%%PREFIX%%/AntiVir --update $1
