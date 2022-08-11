PORTNAME=	jupyter-jsmol
PORTVERSION=	2021.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	science devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	JSmol viewer widget for Jupyter Notebooks and JupyterLab

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>0:devel/py-widgetsnbextension@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel5>=5.0.0:devel/py-ipykernel5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.0.0:devel/ipython@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	fekad

USES=		python:3.7+ pytest
USE_PYTHON=	distutils
PYDISTUTILS_CONFIGUREARGS=	--skip-npm
PYDISTUTILS_BUILDARGS=		--skip-npm

OPTIONS_DEFINE=		EXAMPLES
EXAMPLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}plotly>0:graphics/py-plotly@${PY_FLAVOR}	\
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

PORTEXAMPLES=	*
PLIST_SUB+=	VER=${PORTVERSION}
NO_ARCH=	yes

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
