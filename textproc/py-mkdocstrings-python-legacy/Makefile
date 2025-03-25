PORTNAME=	mkdocstrings-python-legacy
DISTVERSION=	0.2.6
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocstrings_python_legacy-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Legacy Python handler for mkdocstrings
WWW=		https://github.com/mkdocstrings/python-legacy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-autorefs>=1.1:textproc/py-mkdocs-autorefs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytkdocs>=0.14:textproc/py-pytkdocs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-material>0:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.28.3:textproc/py-mkdocstrings@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' PYTHONLEGACY option).  It was
# therefore # moved to TEST_DEPENDS to at least allow the test suite to run.

USES=		python:3.9+
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python

NO_ARCH=	yes

.include <bsd.port.mk>
