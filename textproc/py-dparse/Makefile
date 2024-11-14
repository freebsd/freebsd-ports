PORTNAME=	dparse
DISTVERSION=	0.6.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parser for Python dependency files
WWW=		https://github.com/pyupio/dparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch>0:devel/py-hatch@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		cpe python
CPE_VENDOR=	pyup
CPE_PRODUCT=	dependency_parser
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		CONDA PIPENV POETRY
OPTIONS_DEFAULT=	CONDA PIPENV POETRY

CONDA_DESC=	Enable support for Conda YML parsing
PIPENV_DESC=	Enable support to update Python Pipfiles
POETRY_DESC=	Enable support for parsing "poetry.lock" files

CONDA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
PIPENV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pipenv>=0:devel/py-pipenv@${PY_FLAVOR}
POETRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR}

.include <bsd.port.mk>
