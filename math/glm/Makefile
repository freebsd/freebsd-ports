PORTNAME=	glm
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	math graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL
WWW=		https://github.com/g-truc/glm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	g-truc
NO_ARCH=	yes
CMAKE_OFF=	GLM_BUILD_LIBRARY

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS
TEST_CMAKE_BOOL=	GLM_TEST_ENABLE
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
