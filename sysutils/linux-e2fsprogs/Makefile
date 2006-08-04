# New ports collection makefile for:	linux-e2fsprogs
# Date created:		2006-08-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	e2fsprogs
PORTVERSION=	1.38
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-0.FC4.1

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Utilities and library to manipulate ext2/3 filesystems (Linux version)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
AUTOMATIC_PLIST=yes
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
