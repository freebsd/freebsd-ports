# New ports collection makefile for:	linux-expat
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.8
PORTREVISION=	2
CATEGORIES=	textproc linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-6

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux/i386 binary port of Expat XML-parsing library

CONFLICTS=	linux-f8-expat-[0-9]* linux-f10-expat-[0-9]*

BRANDELF_DIRS=	usr/bin

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
ONLY_FOR_ARCHS=	i386 amd64
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
