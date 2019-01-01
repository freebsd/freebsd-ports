# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aiohttp
PORTVERSION=	2.3.10
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client/server for asyncio

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async_timeout>=1.2.0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna_ssl>=1.0.0:dns/py-idna_ssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=4.0.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.0.0:www/py-yarl@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${FLAVOR}

USES=		python:3.4+
USE_PYTHON=	autoplist cython distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/aiohttp/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
