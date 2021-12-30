PORTNAME=	mbedtls
PORTVERSION=	2.28.0
DISTVERSIONPREFIX=${PORTNAME}-
CATEGORIES=	security devel

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SSL/TLS and cryptography library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python:test shebangfix
SHEBANG_FILES=	scripts/*.py tests/scripts/*.py

USE_GITHUB=	yes
GH_ACCOUNT=	ARMmbed

ALL_TARGET=	no_test
TEST_TARGET=	test
MAKE_ENV=	PYTHON=${PYTHON_CMD} SHARED=1
USE_LDCONFIG=	yes

post-patch:
	@${RM} ${WRKSRC}/include/mbedtls/*.orig
	@${REINPLACE_CMD} \
		-e 's/PREFIX/NAMEPREFIX/' \
		-e 's/$$(DESTDIR)/&$$(PREFIX)/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/-fpic//' ${WRKSRC}/library/Makefile

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/bin -type f -not -name \*.sh \
		-exec ${STRIP_CMD} {} +
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
