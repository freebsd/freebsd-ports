PORTNAME=	mkdocs-autorefs
DISTVERSION=	1.4.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_autorefs-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Automatically link across pages in MkDocs
WWW=		https://github.com/mkdocstrings/autorefs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=3.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0.1:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.1:textproc/py-mkdocs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}griffe>0:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>0:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>0:textproc/py-mkdocstrings@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# Prevent packaging of the Mypy cache folder
post-extract:
	@${RM} -r ${WRKSRC}/src/mkdocs_autorefs/.mypy_cache \
		${WRKSRC}/src/mkdocs_autorefs/_internal/.mypy_cache

.include <bsd.port.mk>
