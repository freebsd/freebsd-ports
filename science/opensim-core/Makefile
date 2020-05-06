# $FreeBSD$

PORTNAME=	OpenSim
DISTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	science
PKGNAMESUFFIX=	-core

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for modeling of musculoskeletal structures

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libdocopt.so:devel/docopt.cpp \
		libSimTKcommon.so:science/simbody

USES=		blaslapack:openblas cmake compiler:c++11-lib fortran gl shebangfix xorg # fortran only for simbody/openblas
SHEBANG_FILES=	Applications/opensim-install-command-line.sh
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}-org
GH_PROJECT=	${PORTNAME:tl}-core
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${LOCALBASE}/include/docopt
CONFIGURE_ENV+=	SIMBODY_HOME=${LOCALBASE}
CMAKE_OFF=	OPENSIM_COPY_DEPENDENCIES DO_TESTING

OPTIONS_DEFINE=		PYTHON JAVA DOCS
OPTIONS_DEFAULT=	PYTHON JAVA
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	BUILD_PYTHON_WRAPPING
PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30

JAVA_CMAKE_BOOL=	BUILD_JAVA_WRAPPING
JAVA_CMAKE_ON=		-DJAVA_AWT_LIBRARY=${LOCALBASE}/openjdk8/jre/lib/amd64/libawt.so \
			-DJAVA_JVM_LIBRARY=${LOCALBASE}/openjdk8/jre/lib/amd64/server/libjvm.so \
			-DJAVA_INCLUDE_PATH=${LOCALBASE}/openjdk8/include
JAVA_USE=		JAVA=yes
JAVA_BUILD_DEPENDS=	swig3.0:devel/swig30

DOCS_CMAKE_BOOL=	INSTALL_DOCS
PORTDOCS=		*

do-test: # 4 testcases are known to fail: https://github.com/opensim-org/opensim-core/issues/2379
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDO_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
