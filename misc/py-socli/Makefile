# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	socli
PORTVERSION=	3.7
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Stack overflow command line interface

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=0:devel/py-backports.functools_lru_cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stackexchange>=0:devel/py-stackexchange@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	gautamkrishnar

NO_ARCH=	yes

.include <bsd.port.mk>
