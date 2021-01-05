# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	s2n
PORTVERSION=	0.10.23
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	security

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C99 implementation of the TLS/SSL protocols

LICENSE=	APACHE20

USES=		cmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

SUB_FILES=	pkg-message

post-build-TEST-on:
	(cd ${WRKDIR}/.build && ninja test)

post-install:
	${LN} -s libs2n.so ${STAGEDIR}${LOCALBASE}/lib/libs2n.so.0
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/*.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
