PORTNAME=	pdjson
DISTVERSION=	g20250825
CATEGORIES=	textproc

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Public Domain JSON Parser Library for C

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	skeeto
GH_TAGNAME=	78fe04b820dc8817f540bdd87fb22887e0ef3981
USE_LDCONFIG=	yes

TEST_TARGET=	check

SUB_FILES=	pdjson.pc
SUB_LIST=	DISTVERSION=${DISTVERSION}

do-install:
	${INSTALL_LIB} ${WRKSRC}/libpdjson.so ${STAGEDIR}${LOCALBASE}/lib/libpdjson.so.0
	${RLN} ${STAGEDIR}${LOCALBASE}/lib/libpdjson.so.0  ${STAGEDIR}${LOCALBASE}/lib/libpdjson.so
	${INSTALL} ${WRKSRC}/pdjson.h ${STAGEDIR}${LOCALBASE}/include
	${INSTALL_DATA} ${WRKDIR}/pdjson.pc ${STAGEDIR}${LOCALBASE}/libdata/pkgconfig

.include <bsd.port.mk>
