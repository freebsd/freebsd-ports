# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gspread
PORTVERSION=	3.5.0
DISTVERSIONPREFIX=     v
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Google Spreadsheets Python API

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.2.1:www/py-requests@${PY_FLAVOR}

USES=	python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=     yes
GH_ACCOUNT=     burnash

.include <bsd.port.mk>
