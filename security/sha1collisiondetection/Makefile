# $FreeBSD$

PORTNAME=	sha1collisiondetection
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	stable-v
CATEGORIES=	security

MAINTAINER=	jharris@widomaker.com
COMMENT=	Library and command line tool to detect SHA-1 collisions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	cr-marcstevens

USE_LDCONFIG=	yes

PLIST_FILES=	bin/sha1dcsum \
		bin/sha1dcsum_partialcoll \
		include/sha1dc/sha1.h \
		lib/libsha1detectcoll.so \
		lib/libsha1detectcoll.so.1 \
		lib/libsha1detectcoll.so.1.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/.libs/sha1dcsum* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/sha1dc
	${INSTALL_DATA} ${WRKSRC}/lib/sha1.h ${STAGEDIR}${PREFIX}/include/sha1dc
	${INSTALL_LIB} ${WRKSRC}/bin/.libs/libsha1detectcoll.so.1.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libsha1detectcoll.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libsha1detectcoll.so
	${LN} -sf libsha1detectcoll.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libsha1detectcoll.so.1

.include <bsd.port.mk>
