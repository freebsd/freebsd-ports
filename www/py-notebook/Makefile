PORTNAME=	notebook
DISTVERSION=	7.2.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web-based notebook environment for interactive computing
WWW=		https://jupyter.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.11:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.2.0<4.4:devel/py-jupyterlab@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.4.0<3:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.2.0<4.4:devel/py-jupyterlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-server>=2.27.1<3:devel/py-jupyterlab-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook-shim>=0.2<0.3:devel/py-notebook-shim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2.0:www/py-tornado@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbval>0:devel/py-nbval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>0:devel/py-pytest-console-scripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-tornasync>0:devel/py-pytest-tornasync@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.4.0:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-server>=2.27.1:devel/py-jupyterlab-server@${PY_FLAVOR}

USES=		cpe desktop-file-utils python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail to run, see https://github.com/jupyter/notebook/issues/7451

NO_ARCH=	yes

CPE_VENDOR=	jupyter

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
