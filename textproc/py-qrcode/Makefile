# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	qrcode
PORTVERSION=	5.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kyuupichan@gmail.com
COMMENT=	QR Code image generator

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py-pillow@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
