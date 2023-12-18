PORTNAME=	fmtlib
PORTVERSION=	10.1.1
CATEGORIES=	textproc devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Modern formatting library (formerly cppformat)
WWW=		https://fmt.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cmake

USE_GITHUB=	uh-huh
GH_ACCOUNT=	fmtlib
GH_PROJECT=	fmt

OPTIONS_DEFINE=	TEST

CMAKE_ON=	BUILD_SHARED_LIBS
TEST_CMAKE_OFF=	-DFMT_TEST=0
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
