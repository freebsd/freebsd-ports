PORTNAME=	topologic
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0-21
DISTVERSIONSUFFIX=	-gae5ad5d
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-space-modeling-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for topological representations of architectural spaces

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libTopologicCore.so:math/topologic \
		libTKernel.so:cad/opencascade

USES=		cmake compiler:c++17-lang localbase:ldflags python

USE_GITHUB=	yes
GH_ACCOUNT=	wassimj
GH_PROJECT=	Topologic

WRKSRC_SUBDIR=	Python-Bindings

CXXFLAGS+=	-I${LOCALBASE}/include/OpenCASCADE

PLIST_FILES=	${PYTHON_SITELIBDIR}/topologic${PYTHON_EXT_SUFFIX}.so

do-install: # workaround for https://github.com/wassimj/Topologic/issues/34
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/topologic.cpython-38.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test: install
	${PYTHON_CMD} ${WRKSRC}/test/topologictest01.py

.include <bsd.port.mk>
