# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.12
CATEGORIES=	net
MASTER_SITES=	SF/fsp/${PORTNAME}/${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Library implementing FSP protocol

LICENSE=	FSPSSC
LICENSE_NAME=	FSP software suite copyright
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		scons
CCFLAGS=	${CXXFLAGS}

PLIST_FILES=	include/fsplib.h lib/libfsplib.a

OPTIONS_DEFINE=	SHARED
SHARED_DESC=	Install shared library (EXPERIMENTAL)

SHARED_MAKE_ARGS=	enable-shared=1
SHARED_PLIST_FILES=	lib/libfsplib.so.0.0.0

post-patch:
	${REINPLACE_CMD} '-e s|/usr/local|${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/SConstruct

.include <bsd.port.mk>
