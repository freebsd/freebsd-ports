# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ls-qpack
PORTVERSION=	2.2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	QPACK compression library for use with HTTP/3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxxhash.so:devel/xxhash

USES=		cmake compiler:c11

CMAKE_OFF=	LSQPACK_TESTS
CMAKE_ON=	BUILD_SHARED_LIBS LSQPACK_BIN LSQPACK_XXH

GH_ACCOUNT=	litespeedtech
USE_GITHUB=	yes

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/deps/

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/encode-int ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/fuzz-decode ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/interop-decode ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/interop-encode ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/huff-tables.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/lsqpack.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/lsxpack_header.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_LIB} ${INSTALL_WRKSRC}/libls-qpack.so ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
