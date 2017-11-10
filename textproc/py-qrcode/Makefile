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

USES?=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 3000
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py3-pillow
.else
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py-pillow
.endif

.include <bsd.port.post.mk>

