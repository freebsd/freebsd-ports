PORTNAME=	xonsh
DISTVERSION=	0.18.2
CATEGORIES=	shells python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Python-powered, cross-platform, Unix-gazing shell
WWW=		https://xon.sh

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyte>0:devel/py-pyte@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subprocess>0:devel/py-pytest-subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test_builtins.py test_commands_cache.py \
			test_integrations.py test_main.py test_man.py \
			test_ptk_highlight.py test_virtualenv_activator.py \
			test_bash_completer.py test_dir_completers.py
SHEBANG_FILES=	tests/bin/cat tests/bin/pwd tests/bin/wc
#TESTS WIP

NO_ARCH=	yes

.include <bsd.port.mk>
