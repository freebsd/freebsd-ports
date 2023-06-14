PORTNAME=	jupyter-jsmol
PORTVERSION=	2022.1.0
CATEGORIES=	science devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${DISTVERSIONFULL}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	JSmol viewer widget for Jupyter Notebooks and JupyterLab
WWW=		https://github.com/fekad/jupyter-jsmol

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>=0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}widgetsnbextension>0:devel/py-widgetsnbextension@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=5.0.0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.0.0:devel/ipython@${PY_FLAVOR}

USES=		python pytest
USE_PYTHON=	distutils
PYDISTUTILS_CONFIGUREARGS=	--skip-npm
PYDISTUTILS_BUILDARGS=		--skip-npm

PLIST_SUB+=	VER=${PORTVERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
