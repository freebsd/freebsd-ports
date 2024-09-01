PORTNAME=	python-lsp-server
PORTVERSION=	1.12.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME:S/-/_/g}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Python implementation of the Language Server Protocol
WWW=		https://github.com/python-lsp/python-lsp-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autopep8>0:textproc/py-autopep8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docstring-to-markdown>0:textproc/py-docstring-to-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydocstyle>0:devel/py-pydocstyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>0:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyls-black>0:devel/py-pyls-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-lsp-jsonrpc>0:textproc/py-python-lsp-jsonrpc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rope>0:devel/py-rope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whatthepatch>0:textproc/py-whatthepatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>0:textproc/py-yapf@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>=3.4.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jedi>0:devel/py-jedi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>0:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-isort>0:devel/py-pytest-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rope>0:devel/py-rope@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whatthepatch>0:textproc/py-whatthepatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yapf>0:textproc/py-yapf@${PY_FLAVOR} \
		${PYNUMPY}

### Test core dumps at
# python_lsp_server-1.12.0/test/plugins/test_autoimport.py:l277ff
# if math/openblas is built with option INTERFACE64=ON (nondefault)!
#
# make test: 4 failed, 186 passed, 8 skipped, 10 warnings
USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_USES=	qt:5
TEST_USE_PYQT=	pyqt5:test
TEST_USE_QT=	testlib

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${DISTFILES:R:R}

.include <bsd.port.mk>
