PORTNAME=	shell-gpt
DISTVERSION=	0.8.8
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command-line productivity tool powered by ChatGPT
WWW=		https://github.com/TheR1D/shell_gpt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typer>=0.7.0<0.8:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.8.0<1.9:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.3.1<13.4:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.2<2.29:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-mock>0:www/py-requests-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes

# Temporarily disable test since upstream removed from test files from distribution.
# See https://github.com/TheR1D/shell_gpt/issues/135 for discussion.
# do-test:
# 	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest tests/unittests.py
# 	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest tests/integrational_tests.py

.include <bsd.port.mk>
