PORTNAME=	pytkdocs
DISTVERSION=	0.16.5
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Load Python objects documentation
WWW=		https://github.com/mkdocstrings/pytkdocs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>0:devel/py-pydantic@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		NUMPYSTYLE
OPTIONS_DEFAULT=	NUMPYSTYLE

NUMPYSTYLE_DESC=	Enable support for Numpy docstrings
NUMPYSTYLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docstring_parser>=0.7:textproc/py-docstring_parser@${PY_FLAVOR}

.include <bsd.port.mk>
