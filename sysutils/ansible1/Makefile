# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PKGNAMESUFFIX=	1
PORTVERSION=	1.9.6
PORTREVISION=

CONFLICTS=	ansible-*

MASTERDIR=	${.CURDIR}/../ansible
DISTINFO_FILE=	${.CURDIR}/distinfo

SHEBANG_FILES=	lib/ansible/runner/action_plugins/synchronize.py

EXTRA_PATCHES=

DEPRECATED=		please upgrade to sysutils/ansible
EXPIRATION_DATE=	2016-10-01

.include "${MASTERDIR}/Makefile"
