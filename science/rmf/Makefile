PORTNAME=	rmf
DISTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	science graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to support reading and writing of Rich Molecular Format files
WWW=		https://integrativemodeling.org/rmf/ \
		https://github.com/salilab/rmf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhdf5.so:science/hdf5

USES=		compiler:c++17-lang cmake:testing localbase:ldflags python:build shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	salilab

SHEBANG_GLOB=	*.py

LDFLAGS+=	-lhdf5

BINARY_ALIAS=	python=${PYTHON_CMD}

do-test:
	@${RM} ${WRKSRC}/test/*.py
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFREEBSD_BUILS_WITH_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
