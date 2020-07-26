# $FreeBSD$

PORTNAME=	taxii2-client
PORTVERSION=	2.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Minimal client implementation for the TAXII 2.0 server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0:devel/py-responses@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	oasis-open
GH_PROJECT=	cti-taxii-client

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

DO_MAKE_TEST=	${SETENV} ${TEST_ENV} pytest-${PYTHON_VER} --cov=taxii2client taxii2client/test/ --cov-report term-missing
TEST_TARGET=	# empty
NO_ARCH=	yes

.include <bsd.port.mk>
