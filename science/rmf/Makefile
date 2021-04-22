PORTNAME=	rmf
DISTVERSION=	1.3
CATEGORIES=	science graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to support reading and writing of Rich Molecular Format files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip

USES=		compiler:c++11-lang cmake python:build shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	salilab

SHEBANG_GLOB=	*.py

BINARY_ALIAS=	python=${PYTHON_CMD}

do-test:
	@${RM} ${WRKSRC}/test/*.py
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFREEBSD_BUILS_WITH_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
