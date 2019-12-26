# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycryptopp
PORTVERSION=	0.7.1.869544967005693312591928092448767568728501330214
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Wrappers for the Crypto++ Library

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}darcsver>0:devel/py-darcsver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_darcs>0:devel/py-setuptools_darcs@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
