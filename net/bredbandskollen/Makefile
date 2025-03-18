PORTNAME=	bredbandskollen
DISTVERSIONPREFIX=	BBK_CLI_
DISTVERSION=	1.2.2
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Command line tool to check internet connection speed
WWW=		https://github.com/dotse/bbk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dotse
GH_PROJECT=	bbk

BUILD_WRKSRC=	${WRKSRC}/src/cli

PLIST_FILES=	bin/bbk_cli \
		bin/bredbandskollen

OPTIONS_DEFINE=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_MAKE_ARGS=	GNUTLS=1

post-patch:
	${REINPLACE_CMD} -e 's/CXX = c++/CXX ?= c++/g' \
	${WRKSRC}/src/framework/mk.inc

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cli ${STAGEDIR}/${PREFIX}/bin/bbk_cli
	${LN} -sf bbk_cli ${STAGEDIR}/${PREFIX}/bin/bredbandskollen

do-test:
	cd ${WRKSRC}/src/test && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>
