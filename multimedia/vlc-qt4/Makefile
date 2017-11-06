# Created by: nox@FreeBSD.org
# $FreeBSD$

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Qt 4 based multimedia player and streaming server
PKGNAMESUFFIX=	-qt4

OPTIONS_SLAVE=	QT4
OPTIONS_EXCLUDE=	QT5

CONFLICTS=	vlc-[0-9]*

BROKEN_powerpc64=	fails to compile: modules/plugins.dat: Segmentation fault (core dumped)

MASTERDIR=	${.CURDIR}/../vlc

.include "${MASTERDIR}/Makefile"
