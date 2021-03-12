# Created by: demon@FreeBSD.org
# $FreeBSD$

PORTNAME=	glm
PORTVERSION=	0.9.9.8
PORTEPOCH=	1
CATEGORIES=	math graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL

LICENSE=	MIT

USES=		cmake compiler:c++11-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	g-truc
NO_ARCH=	yes

SUB_FILES=	glm.pc

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS
TEST_CMAKE_BOOL=	GLM_TEST_ENABLE
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e '/printf/ s|EndTime - StartTime|static_cast<long>(&)|' \
		${WRKSRC}/test/core/core_func_matrix.cpp

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "glm" ${STAGEDIR}${PREFIX}/include \
		"-not -name CMakeLists.txt"
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/glm
	${INSTALL_DATA} ${WRKSRC}/cmake/glm/*.cmake ${STAGEDIR}${PREFIX}/lib/cmake/glm
	${INSTALL_DATA} ${WRKDIR}/glm.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

do-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "doc *.md" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
