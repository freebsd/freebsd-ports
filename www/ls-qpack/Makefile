PORTNAME=	ls-qpack
PORTVERSION=	2.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	QPACK compression library for use with HTTP/3
WWW=		https://github.com/litespeedtech/ls-qpack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxxhash.so:devel/xxhash

USES=		cmake compiler:c11 pathfix pkgconfig

CMAKE_OFF=	LSQPACK_TESTS \
		LSQPACK_XXH
CMAKE_ON=	BUILD_SHARED_LIBS \
		LSQPACK_BIN

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	litespeedtech
USE_GITHUB=	yes

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/deps/

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
