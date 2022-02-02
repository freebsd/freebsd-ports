PORTNAME=	dionysus
PORTVERSION=	g20210521
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-topology-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing persistent homology

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/adaptors.hpp:devel/boost-libs

USES=		cmake python

USE_GITHUB=	yes
GH_ACCOUNT=	mrzv
GH_TAGNAME=	ae27bb1

CMAKE_ARGS=	-DPython_EXECUTABLE:STRING=${PYTHON_CMD}
CMAKE_OFF=	build_examples

PLIST_FILES=	${PYTHON_SITELIBDIR}/dionysus/__init__.py \
		${PYTHON_SITELIBDIR}/dionysus/_dionysus${PYTHON_EXT_SUFFIX}.so \
		${PYTHON_SITELIBDIR}/dionysus/_version.py \
		${PYTHON_SITELIBDIR}/dionysus/plot.py

do-install:
	cd ${BUILD_WRKSRC}/bindings/python && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
