# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
DISTVERSION=	2.5
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex networks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}decorator>=4.3.0:devel/py-decorator@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_GLOB=	*.py
NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}networkx1

PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=	EXAMPLES GDAL LXML PANDAS PYDOT YAML
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	MPL GRAPHVIZ
OPTIONS_DEFAULT=	NUMPY SCIPY MPL GDAL GRAPHVIZ LXML PANDAS PYDOT YAML

NUMPY_DESC=	Matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2,1:math/py-numpy@${PY_FLAVOR}

SCIPY_DESC=	Sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.15.1:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:science/py-scikit-sparse@${PY_FLAVOR}

MPL_DESC=	Flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.0:math/py-matplotlib@${PY_FLAVOR}

GDAL_DESC=	Support of raster geospatial data formats
GDAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=0:graphics/py-gdal@${PY_FLAVOR}

GRAPHVIZ_DESC=	Additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.2:graphics/py-pygraphviz@${PY_FLAVOR}

LXML_DESC=	Binding for the libxml2 and libxslt libraries
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

PANDAS_DESC=	Data analysis
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}

PYDOT_DESC=	Graphviz Dot language
PYDOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot@${PY_FLAVOR}

YAML_DESC=	Reading and writing YAML files
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
