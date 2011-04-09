# New ports collection makefile for:    wv2
# Date created:         Do 28 Aug 2003 15:50:37 CEST
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	wv2
PORTVERSION=	0.4.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/wvware/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A library providing routines to access Microsoft Word files

USE_GNOME=	gnometarget libgsf
USE_ICONV=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE?= Debug
.else
CMAKE_BUILD_TYPE?= Release
.endif

PLIST_SUB=	CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE:L}"

.include <bsd.port.mk>
