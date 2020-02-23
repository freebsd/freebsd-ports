# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gspread
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=     v
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Google Spreadsheets Python API

USE_GITHUB=     yes
GH_ACCOUNT=     burnash

LICENSE=	MIT

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.2.1:www/py-requests@${PY_FLAVOR}

USES=	python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
