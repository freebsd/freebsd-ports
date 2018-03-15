# $FreeBSD$

PORTNAME=	mbedtls
PORTVERSION=	2.7.1
DISTVERSIONPREFIX=${PORTNAME}-
CATEGORIES=	security devel

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	SSL/TLS and cryptography library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/apache-2.0.txt

USE_GITHUB=	yes
GH_ACCOUNT=	ARMmbed

ALL_TARGET=	no_test
TEST_TARGET=	test
MAKE_ENV=	SHARED=1
USES=		gmake tar:tgz
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	polarssl13-[0-9]*

post-patch:
	@${RM} ${WRKSRC}/include/mbedtls/*.orig
	@${REINPLACE_CMD} \
		-e 's/PREFIX/NAMEPREFIX/' \
		-e 's/$$(DESTDIR)/&$$(PREFIX)/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/-fpic//' ${WRKSRC}/library/Makefile

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f | \
		${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
