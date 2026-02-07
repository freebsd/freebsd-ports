PORTNAME=	rmf
DISTVERSION=	1.7.0
CATEGORIES=	science graphics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to support reading and writing of Rich Molecular Format files
WWW=		https://integrativemodeling.org/rmf/ \
		https://github.com/salilab/rmf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libRMF.so:science/rmf

USES=		cmake compiler:c++11-lang localbase:ldflags python shebangfix
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	salilab

SHEBANG_GLOB=	*.py

CMAKE_ARGS=	-DCMAKE_INSTALL_PYTHONDIR:STRING=${PYTHON_SITELIBDIR}

LDFLAGS+=	-lRMF

BINARY_ALIAS=	python=${PYTHON_CMD}

do-test:
	# the IMP_MEDIUM_TIMEOUT setting below is to prevent RMF-medium_test_backwards.py from timeing out, see https://github.com/salilab/rmf/issues/126#issuecomment-825145818
	@${RM} ${WRKSRC}/test/*.cpp
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFREEBSD_BUILS_WITH_TESTS:BOOL=ON -DIMP_MEDIUM_TIMEOUT=1000000 ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
