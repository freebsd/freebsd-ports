# New ports collection makefile for:	linux e2fsprogs
# Date created:		Sat Feb 15 19:19:59 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
CATEGORIES=	sysutils linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of the a set of utilities and library to manipulate an ext2 filesystem

.if ${MACHINE_ARCH} == "i386"
PORTVERSION=	1.19.4
RPM_SET=	e2fsprogs-1.19-4.${MACHINE_ARCH}.rpm
.endif
.if ${MACHINE_ARCH} == "alpha"
PORTVERSION=	1.19.5
PORTREVISION=	1
RPM_SET=	e2fsprogs-1.19-5.${MACHINE_ARCH}.rpm
.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
