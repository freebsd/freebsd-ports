PORTNAME=	jupyterlab-pygments
PORTVERSION=	0.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jupyterlab_pygments-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pygments theme using JupyterLab CSS variables
WWW=		https://github.com/jupyterlab/jupyterlab_pygments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-nodejs-version>=0.3.2:devel/py-hatch-nodejs-version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.5.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=2.4.1<3:textproc/py-pygments@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
