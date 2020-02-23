# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	fedex
PORTVERSION=	2.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Light wrapper around Fedex's Web Services SOAP API using suds

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}suds>=0:net/py-suds@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
