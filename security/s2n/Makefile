# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s2n
PORTVERSION=	20160628
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the TLS/SSL protocols

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs
GH_TAGNAME=	2bae833

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		gmake ssl
USE_LDCONFIG=	yes
NO_CONFIGURE=	yes

SUB_FILES=	pkg-message Makefile
ALL_TARGET=	bin

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS |&+|' ${WRKSRC}/s2n.mk
	@${REINPLACE_CMD} -e 's|CRYPTO_LDFLAGS |&+|' \
		${WRKSRC}/tests/testlib/Makefile \
		${WRKSRC}/tests/unit/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libs2n.so* ${STAGEDIR}${LOCALBASE}/lib
	${LN} -s libs2n.so ${STAGEDIR}${LOCALBASE}/lib/libs2n.so.0
	${INSTALL_DATA} ${WRKSRC}/api/s2n* ${STAGEDIR}${LOCALBASE}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/Makefile ${STAGEDIR}${EXAMPLESDIR}

tests: build
	${GMAKE} PLATFORM=FreeBSD CRYPTO_LDFLAGS=-L${LOCALBASE}/lib -C ${WRKSRC}/tests

.include <bsd.port.mk>
