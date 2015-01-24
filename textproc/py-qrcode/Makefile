# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	qrcode
PORTVERSION=	5.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	QR Code image generator

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:${PORTSDIR}/graphics/py-pillow

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
