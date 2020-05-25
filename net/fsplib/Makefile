# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.14
CATEGORIES=	net
MASTER_SITES=	SF/fsp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library implementing FSP protocol

LICENSE=	FSPSSC
LICENSE_NAME=	FSP software suite copyright
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		scons:python2

CCFLAGS=	${CXXFLAGS}

PLIST_FILES=	include/fsplib.h lib/libfsplib.a
NO_WRKSUBDIR=	yes
MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	SHARED
SHARED_DESC=	Install shared library (EXPERIMENTAL)

SHARED_MAKE_ARGS=	enable-shared=1
SHARED_PLIST_FILES=	lib/libfsplib.so.0.0.0

.include <bsd.port.mk>
