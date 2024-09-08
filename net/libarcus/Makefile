PORTNAME=	libArcus
PORTVERSION=	5.3.0
PORTEPOCH=	1
CATEGORIES=	net cad
DIST_SUBDIR=	Ultimaker

MAINTAINER=	db@FreeBSD.org
COMMENT=	Communication library between internal components for Ultimaker
WWW=		https://github.com/Ultimaker/libArcus

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++17-lang python pyqt:6
USE_PYQT=	pysip
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_TUPLE=	Ultimaker:pyArcus:${PORTVERSION}:pyArcus
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=OFF \
		-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
		-DPYTHON_INCLUDEDIR:STRING=${PYTHON_INCLUDEDIR}

post-extract:
	@${MKDIR} ${WRKSRC}/cmake
	@for f in COPYING-CMAKE-SCRIPTS FindSIP.cmake FindSIP.py SIPMacros.cmake; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}/cmake; \
		done
	@for f in CMakeLists.txt CPackConfig.cmake ArcusConfig.cmake.in; do \
		${CP} ${FILESDIR}/$$f ${WRKSRC}; \
		done
	@${MV} ${WRKSRC_pyArcus}/python ${WRKSRC}
	@${MV} ${WRKSRC_pyArcus}/include/pyArcus ${WRKSRC}/include
	@${MV} ${WRKSRC_pyArcus}/src/PythonMessage.cpp ${WRKSRC}/python

.include <bsd.port.mk>
