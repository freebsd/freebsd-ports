# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Tools for complex networks / Backported version

LICENSE=	BSD3CLAUSE

DEPRECATED=	Obsolete, please use math/py-networkx instead
EXPIRATION_DATE=	2020-11-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTSCOUT=	limit:^1\.
PORTEXAMPLES=	*
SHEBANG_FILES=	examples/graph/atlas.py \
		examples/multigraph/chess_masters.py \
		networkx/generators/tests/test_random_graphs.py

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}py-networkx

OPTIONS_DEFINE=	EXAMPLES YAML
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	GRAPHVIZ MPL
OPTIONS_DEFAULT=	GRAPHVIZ MPL NUMPY SCIPY YAML

GRAPHVIZ_DESC=		Additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.2:graphics/py-pygraphviz@${PY_FLAVOR}

MPL_DESC=		Flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.0:math/py-matplotlib@${PY_FLAVOR}

NUMPY_DESC=		Matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2,1:math/py-numpy@${PY_FLAVOR}

SCIPY_DESC=		Sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.15.1:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:science/py-scikit-sparse@${PY_FLAVOR}

YAML_DESC=		Reading and writing YAML files
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
