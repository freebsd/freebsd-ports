PORTNAME=	rdflib
PORTVERSION=	6.3.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for RDF manipulation
WWW=		https://github.com/RDFLib/rdflib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.4.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0.6.0<0.7:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.0<4:devel/py-pyparsing@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}berkeleydb>=0:databases/py-berkeleydb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR}

USES=		cpe python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	rdflib_project

SHEBANG_FILES=	rdflib/plugins/parsers/notation3.py

OPTIONS_DEFINE=	HTML
OPTIONS_DEFAULT=HTML
HTML_DESC=	HTML support

HTML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=1.0<2:www/py-html5lib@${PY_FLAVOR}

.include <bsd.port.mk>
