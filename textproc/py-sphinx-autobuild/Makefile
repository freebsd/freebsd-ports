PORTNAME=	sphinx-autobuild
PORTVERSION=	2025.8.25
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_autobuild-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rebuild Sphinx documentation on changes, with hot reloading in the browser
WWW=		https://github.com/sphinx-doc/sphinx-autobuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.35:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.25:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0.20:devel/py-watchfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=11:devel/py-websockets@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
