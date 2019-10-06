# $FreeBSD$

PORTNAME=	darknet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4-1614
DISTVERSIONSUFFIX=	-gd703fb4e
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source neural networks in C

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pjreddie
GH_TAGNAME=	61c9d02
USE_LDCONFIG=	yes

MAKE_ARGS=	OPTS=-O3

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

PLIST_FILES=	bin/darknet \
		include/darknet.h \
		lib/libdarknet.a \
		lib/libdarknet.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darknet ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} include ${STAGEDIR}${PREFIX}
	${INSTALL_DATA} ${WRKSRC}/libdarknet.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdarknet.a ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libdarknet.so

.include <bsd.port.mk>
