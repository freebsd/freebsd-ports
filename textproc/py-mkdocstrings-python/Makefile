PORTNAME=	mkdocstrings-python
DISTVERSION=	1.18.2
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}griffe>=1.13.0:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-autorefs>=1.4:textproc/py-mkdocs-autorefs@${PY_FLAVOR}
# textproc/py-mkdocstrings belongs to RUN_DEPENDS as well but would cause
# a circular dependency (via py-mkdocstrings' PYTHON option).  It was therefore
# moved to TEST_DEPENDS to at least allow the test suite to run.
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.12.3:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inline-snapshot>=0.18.1:devel/py-inline-snapshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>=9.5:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.30.0:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.4:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}mkdocstrings-python-legacy

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
