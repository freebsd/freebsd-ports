# Created by: Christer Edwards <christer.edwards@gmail.com>
# $FreeBSD$

PORTNAME=	raet
PORTVERSION=	0.6.8
PORTREVISION=	0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Reliable Asynchronous Event Transport protocol library

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=1.1:devel/py-setuptools-git@${PY_FLAVOR}

USES=		python:2.7

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
