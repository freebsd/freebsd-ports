PORTNAME=	OpenSim
DISTVERSION=	4.6
CATEGORIES=	science
PKGNAMESUFFIX=	-core

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for modeling of musculoskeletal structures
WWW=		https://opensim.stanford.edu/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libipopt.so:math/ipopt \
		libcasadi.so:math/casadi \
		libspdlog.so:devel/spdlog \
		libdocopt.so:devel/docopt.cpp \
		libSimTKcommon.so:science/simbody
TEST_DEPENDS=	catch2>0:devel/catch2

USES=		blaslapack:openblas cmake compiler:c++20-lang fortran gl pkgconfig shebangfix xorg # fortran only for simbody/openblas
SHEBANG_FILES=	Applications/opensim-install-command-line.sh
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}-org
GH_PROJECT=	${PORTNAME:tl}-core
USE_GL=		gl glu glut
JAVA_VERSION=	25
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

BINARY_ALIAS=	git=false
CXXFLAGS+=	-I${LOCALBASE}/include/docopt
CONFIGURE_ENV+=	SIMBODY_HOME=${LOCALBASE}
CMAKE_OFF=	DO_TESTING

OPTIONS_DEFINE=		PYTHON JAVA DOCS
OPTIONS_DEFAULT=	PYTHON JAVA
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON_WRAPPING
PYTHON_CMAKE_OFF=	OPENSIM_COPY_DEPENDENCIES
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig:devel/swig \
			${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

JAVA_CMAKE_BOOL=	BUILD_JAVA_WRAPPING
JAVA_CMAKE_OFF=		OPENSIM_COPY_DEPENDENCIES
JAVA_CMAKE_ON=		-DJAVA_AWT_LIBRARY=${JAVA_HOME}/lib/libawt.so \
			-DJAVA_JVM_LIBRARY=${JAVA_HOME}/lib/server/libjvm.so \
			-DJAVA_INCLUDE_PATH=${JAVA_HOME}/include
JAVA_USES=		java
JAVA_BUILD_DEPENDS=	swig:devel/swig

DOCS_BUILD_DEPENDS=	pdflatex:print/tex-formats
DOCS_CMAKE_BOOL=	INSTALL_DOCS
DOCS_CMAKE_OFF=		OPENSIM_DOXYGEN_USE_MATHJAX
PORTDOCS=		*

do-test: # 4 testcases are known to fail: https://github.com/opensim-org/opensim-core/issues/2379
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDO_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
