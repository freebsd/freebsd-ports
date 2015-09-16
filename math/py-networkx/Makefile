# Created by: dikshie
# $FreeBSD$

PORTNAME=	networkx
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://networkx.lanl.gov/download/networkx/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dikshie@sfc.wide.ad.jp
COMMENT=	Tools for complex networks

LICENSE=	BSD3CLAUSE

RUN_DEPENDS:=	${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:${PORTSDIR}/devel/py-decorator

#		${PYTHON_PKGNAMEPREFIX}sphinx>=1.2.3:${PORTSDIR}/textproc/py-sphinx \
#		${PYTHON_PKGNAMEPREFIX}docutils>=0.12:${PORTSDIR}/textproc/py-docutils

USES=		python shebangfix
USE_PYTHON=	distutils autoplist

PLIST_SUB+=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER}

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_GROUP=	MATRIX RENDER
OPTIONS_GROUP_MATRIX=	NUMPY SCIPY
OPTIONS_GROUP_RENDER=	MPL GRAPHVIZ
OPTIONS_DEFAULT=	NUMPY SCIPY MPL GRAPHVIZ

NUMPY_DESC=	Support matrix representation of graphs
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.2:${PORTSDIR}/math/py-numpy

SCIPY_DESC=	Support sparse matrix representation of graphs
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0.15.1:${PORTSDIR}/science/py-scipy \
			${PYTHON_PKGNAMEPREFIX}scikit-sparse>=0.2:${PORTSDIR}/science/py-scikit-sparse

MPL_DESC=	Support flexible graph rendering
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.0:${PORTSDIR}/math/py-matplotlib

GRAPHVIZ_DESC=	Support additional graph layout and rendering algorithms
GRAPHVIZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphviz>=1.2:${PORTSDIR}/graphics/py-graphviz

EXAMPLESDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
