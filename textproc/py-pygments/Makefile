PORTNAME=	pygments
DISTVERSION=	2.19.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python
WWW=		https://pygments.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.18.0:devel/py-hatchling@${PY_FLAVOR}
# tests: 5186 passed, 7 skipped, 1 warning
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.12.0:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcag-contrast-ratio>=0.9:www/py-wcag-contrast-ratio@${PY_FLAVOR}

USES=		cpe python tex
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_TEX=	latex:test

# We don't want to use Pytest plugins, for example devel/py-ruff, if available in the system
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1

NO_ARCH=	yes

.include <bsd.port.mk>
