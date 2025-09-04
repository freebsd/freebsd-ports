PORTNAME=	verdict
PORTVERSION=	1.4.4
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Compute quality functions of 2 and 3-dimensional regions
WWW=		https://github.com/sandialabs/verdict

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtest.so:devel/googletest

USE_GITHUB=	yes
GH_ACCOUNT=	sandialabs

USES=		cmake:testing
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/SAND2007-2853p.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
