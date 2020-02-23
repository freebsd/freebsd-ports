# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trello
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Python library for interacting with the Trello API

LICENSE=	FOG
LICENSE_NAME=	Fog Creek Software
LICENSE_FILE=	${WRKSRC}/PKG-INFO
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0.9.1:www/py-requests@${PY_FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
