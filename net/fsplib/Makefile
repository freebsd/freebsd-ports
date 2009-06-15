# New ports collection makefile for:	fsplib
# Date created:				15 Jan 2005
# Whom:					X
#
# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.11
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fsp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library implementing FSP protocol

NO_WRKSUBDIR=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX}

PLIST_FILES=	include/fsplib.h lib/libfsplib.a

OPTIONS=	SHARED "Install shared library (EXPERIMENTAL)" OFF

.include <bsd.port.options.mk>

.if defined(WITH_SHARED)
SCONS_ARGS+=	enable-shared=1
PLIST_FILES+=	lib/libfsplib.so.0.0.0
.endif

.include <bsd.port.mk>
