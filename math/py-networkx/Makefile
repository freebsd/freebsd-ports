# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
DISTVERSION=	2.1
PORTEPOCH=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex networks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}decorator>=4.1.0:devel/py-decorator@${PY_FLAVOR}

#		${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.3:textproc/py-sphinx@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils@${PY_FLAVOR}

USES=		python shebangfix zip
USE_PYTHON=	autoplist concurrent distutils
SHEBANG_GLOB=	*.py
NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}networkx1

PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=	EXAMPLES YAML
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	MPL GRAPHVIZ
OPTIONS_DEFAULT=	NUMPY SCIPY MPL GRAPHVIZ YAML

NUMPY_DESC=	Matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2,1:math/py-numpy@${PY_FLAVOR}

SCIPY_DESC=	Sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.15.1:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:science/py-scikit-sparse@${PY_FLAVOR}

MPL_DESC=	Flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.0:math/py-matplotlib@${PY_FLAVOR}

GRAPHVIZ_DESC=	Additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.2:graphics/py-pygraphviz@${PY_FLAVOR}

YAML_DESC=	Reading and writing YAML files
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
