# $FreeBSD$

PORTNAME=	boringssl
PORTVERSION=	0.0.0.0.2018.10.30.01
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Fork of OpenSSL

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	144d924
USES=		cmake:insource localbase perl5
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=1
USE_LDCONFIG=	yes
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib
TEST_TARGET=	run_tests

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tool/bssl ${STAGEDIR}${PREFIX}/bin/
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include)
	${INSTALL_LIB} ${WRKSRC}/crypto/libcrypto.so ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1.0.0
	${INSTALL_LIB} ${WRKSRC}/ssl/libssl.so ${STAGEDIR}${PREFIX}/lib/libssl.so.1.0.0
	${LN} -sf libcrypto.so.1 ${STAGEDIR}${PREFIX}/lib/libcrypto.so
	${LN} -sf libcrypto.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libcrypto.so.1
	${LN} -sf libssl.so.1 ${STAGEDIR}${PREFIX}/lib/libssl.so
	${LN} -sf libssl.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libssl.so.1

.include <bsd.port.mk>
