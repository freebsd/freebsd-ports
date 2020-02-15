# $FreeBSD$

PORTNAME=	vxl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2-629
DISTVERSIONSUFFIX=	-g9f915deec4
CATEGORIES=	misc science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ libraries for computer vision and image understanding

LIB_DEPENDS=	libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang jpeg
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	openjpeg15

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	X86=""
.else
PLIST_SUB+=	X86="@comment "
.endif

.include <bsd.port.post.mk>
