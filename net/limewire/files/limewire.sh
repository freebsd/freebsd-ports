#!/bin/sh
#
# $FreeBSD$

J2SE_PREEMPTCLOSE=1
export J2SE_PREEMPTCLOSE

cd %%DATADIR%% && %%LOCALBASE%%/bin/javavm -jar LimeWire.jar
