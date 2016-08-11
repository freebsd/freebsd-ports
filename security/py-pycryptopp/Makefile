# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycryptopp
PORTVERSION=	0.7.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.869544967005693312591928092448767568728501330214

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Wrappers for the Crypto++ Library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}darcsver>0:devel/py-darcsver \
		${PYTHON_PKGNAMEPREFIX}setuptools_darcs>0:devel/py-setuptools_darcs
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
