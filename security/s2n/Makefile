# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s2n
PORTVERSION=	20180802
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the TLS/SSL protocols

LICENSE=	APACHE20

USES=		cmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
GH_TAGNAME=	15fa0de

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

USE_LDCONFIG=	yes
CFLAGS+=	-D__USE_BSD=1

SUB_FILES=	pkg-message

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_BUILD_DEPENDS=	gmake:devel/gmake

post-patch:
	@${REINPLACE_CMD} -e 's|CRYPTO_LDFLAGS |&+|' \
		${WRKSRC}/tests/testlib/Makefile \
		${WRKSRC}/tests/unit/Makefile
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/tests/LD_PRELOAD/Makefile \
		${WRKSRC}/tests/fuzz/LD_PRELOAD/Makefile

post-build-TEST-on:
	${GMAKE} PLATFORM=FreeBSD S2N_DONT_MLOCK=yes \
		CRYPTO_LDFLAGS=-L${LOCALBASE}/lib -C ${WRKSRC}/tests

post-install:
	${LN} -s libs2n.so ${STAGEDIR}${LOCALBASE}/lib/libs2n.so.0
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
