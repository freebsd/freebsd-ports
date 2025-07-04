PORTNAME=	notebook
PORTVERSION=	7.4.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web-based notebook environment for interactive computing
WWW=		https://jupyter.org/ \
		https://jupyter-notebook.readthedocs.io/en/stable/ \
		https://github.com/jupyter/notebook

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-jupyter-builder>=0.5:devel/py-hatch-jupyter-builder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.11:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.4.4<4.5:devel/py-jupyterlab@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.4.0<3:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab>=4.4.4<4.5:devel/py-jupyterlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-server>=2.27.1<3:devel/py-jupyterlab-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook-shim>=0.2<0.3:devel/py-notebook-shim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.2.0:www/py-tornado@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=2.4.0<3:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-server>=2.27.1<3:devel/py-jupyterlab-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbval>=0:devel/py-nbval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>=0:devel/py-pytest-console-scripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-tornasync>=0:devel/py-pytest-tornasync@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
# py-jupyter-server[test]
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}flaky>=0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-jupyter>=0.7:devel/py-pytest-jupyter@${PY_FLAVOR}
# py-jupyterlab-server[test]
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}hatch>=0:devel/py-hatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-core>=0.18.0:devel/py-openapi-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.6.0<0.8.0:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>=0:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-spelling>=0:textproc/py-sphinxcontrib-spelling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}strict-rfc3339>=0:devel/py-strict-rfc3339@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}

USES=		cpe desktop-file-utils python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

CPE_VENDOR=	jupyter

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5.0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
