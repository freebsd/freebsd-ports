PORTNAME=	mkdocstrings-python
DISTVERSION=	1.7.5
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocstrings_python-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Python handler for mkdocstrings
WWW=		https://github.com/mkdocstrings/python

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}griffe>=0.37:textproc/py-griffe@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' PYTHON option).  It was therefore
# moved to TEST_DEPENDS to at least allow the test suite to run.

USES=		python
USE_PYTHON=	autoplist pep517 pytest
# These tests relies on files that aren't available in the sdist
PYTEST_IGNORED_TESTS=	test_render_themes test_render_docstring

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python-legacy

NO_ARCH=	yes

.include <bsd.port.mk>
