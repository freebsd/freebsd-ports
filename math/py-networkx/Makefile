# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex networks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator

#		${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.3:textproc/py-sphinx \
#		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:textproc/py-docutils

NO_ARCH=	yes
USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=	EXAMPLES YAML
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	MPL GRAPHVIZ
OPTIONS_DEFAULT=	NUMPY SCIPY MPL GRAPHVIZ YAML

NUMPY_DESC=	Matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2,1:math/py-numpy

SCIPY_DESC=	Sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.15.1:science/py-scipy \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:science/py-scikit-sparse

MPL_DESC=	Flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.0:math/py-matplotlib

GRAPHVIZ_DESC=	Additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.2:graphics/py-pygraphviz

YAML_DESC=	Reading and writing YAML files
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
. if ${PORT_OPTIONS:MMPL} || ${PORT_OPTIONS:MGRAPHVIZ}
BROKEN=		Neither math/py-matplotlib nor graphics/py-graphviz support Python 3.x yet. Please disable both the MPL and GRAPHVIZ options
. endif
.endif

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
