#!/bin/sh
# Secure Shell daemon startup script
# $FreeBSD$

if [ -x __PREFIX__/sbin/sshd ]; then
	__PREFIX__/sbin/sshd && echo -n ' sshd'
fi
