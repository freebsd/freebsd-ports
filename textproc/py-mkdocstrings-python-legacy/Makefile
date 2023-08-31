PORTNAME=	mkdocstrings-python-legacy
DISTVERSION=	0.2.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Legacy Python handler for mkdocstrings
WWW=		https://github.com/mkdocstrings/python-legacy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-pep517>0:devel/py-pdm-pep517@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytkdocs>=0.14:textproc/py-pytkdocs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' PYTHONLEGACY option).  It was
# therefore # moved to TEST_DEPENDS to at least allow the test suite to run.

USES=		python
USE_PYTHON=	autoplist pep517 pytest
PYTEST_IGNORED_TESTS=	render_themes

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python

NO_ARCH=	yes

.include <bsd.port.mk>
