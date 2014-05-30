# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.11
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	SF/fsp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library implementing FSP protocol

NO_WRKSUBDIR=	yes
USES=		scons
MAKE_ARGS=	prefix=${PREFIX}

PLIST_FILES=	include/fsplib.h lib/libfsplib.a

OPTIONS_DEFINE=	SHARED
SHARED_DESC=	Install shared library (EXPERIMENTAL)

SHARED_MAKE_ARGS+=	enable-shared=1
SHARED_PLIST_FILES=	lib/libfsplib.so.0.0.0

INSTALL_TARGET=	install prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
