PORTNAME=	mkdocstrings-python
DISTVERSION=	1.10.9
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}griffe>=0.49:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-autorefs>=1.0:textproc/py-mkdocs-autorefs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs-material>0:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' PYTHON option).  It was therefore
# moved to TEST_DEPENDS to at least allow the test suite to run.

USES=		python
GH_PROJECT=	python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python-legacy

NO_ARCH=	yes

.include <bsd.port.mk>
