# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.11
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	SF/fsp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library implementing FSP protocol

NO_WRKSUBDIR=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX}

PLIST_FILES=	include/fsplib.h lib/libfsplib.a

OPTIONS_DEFINE=	SHARED
SHARED_DESC=	Install shared library (EXPERIMENTAL)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED}
SCONS_ARGS+=	enable-shared=1
PLIST_FILES+=	lib/libfsplib.so.0.0.0
.endif

.include <bsd.port.mk>
