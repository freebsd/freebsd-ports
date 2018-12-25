# $FreeBSD$

PORTNAME=	simbody
DISTVERSIONPREFIX=	Simbody-
DISTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	science biology

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	1b306f66bcd15e9bf6b27882e2daa6375ac4cd2e.patch:-p1 \
		eaff90b304291ab9ffdf60d7abfb48e23e102ecb.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multibody dynamics library for (bio)mechanical systems simulation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		blaslapack:openblas cmake compiler:c++11-lang fortran # fortran only for openblas
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING BUILD_EXAMPLES
CMAKE_ARGS=	-DBLAS_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so -DLAPACK_LIBRARIES:STRING=${LOCALBASE}/lib/libopenblas.so

OPTIONS_DEFINE=		DOCS VISUALIZER
OPTIONS_DEFAULT=	VISUALIZER
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	INSTALL_DOCS

VISUALIZER_CMAKE_BOOL=	BUILD_VISUALIZER
VISUALIZER_USES=	gl
VISUALIZER_USE=		GL=gl,glu,glut XORG=xi,xmu

PORTDOCS=	*

post-install-DOCS-on: # https://github.com/simbody/simbody/issues/652
	@${RMDIR} ${STAGEDIR}${DOCSDIR}/api

do-test: # one test is known to fail: https://github.com/simbody/simbody/issues/653
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
