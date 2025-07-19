PORTNAME=	networkx
DISTVERSION=	3.5
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Tools for complex networks
WWW=		https://networkx.github.io/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
#RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=4.3.0:devel/py-decorator@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

SHEBANG_GLOB=	*.py
NO_ARCH=	yes
CPE_VENDOR=	python

#PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=	EXAMPLES GDAL LXML PANDAS PYDOT YAML
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	MPL GRAPHVIZ
OPTIONS_DEFAULT=	NUMPY SCIPY MPL GDAL GRAPHVIZ LXML PANDAS PYDOT YAML

NUMPY_DESC=	Matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.20.0,1:math/py-numpy@${PY_FLAVOR}

SCIPY_DESC=	Sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=1.8:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:science/py-scikit-sparse@${PY_FLAVOR}

MPL_DESC=	Flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4.0:math/py-matplotlib@${PY_FLAVOR}

GDAL_DESC=	Support of raster geospatial data formats
GDAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=0:graphics/py-gdal@${PY_FLAVOR}

GRAPHVIZ_DESC=	Additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.2:graphics/py-pygraphviz@${PY_FLAVOR}

LXML_DESC=	Binding for the libxml2 and libxslt libraries
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR}

PANDAS_DESC=	Data analysis
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=1.3:math/py-pandas@${PY_FLAVOR}

PYDOT_DESC=	Graphviz Dot language
PYDOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot@${PY_FLAVOR}

YAML_DESC=	Reading and writing YAML files
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
