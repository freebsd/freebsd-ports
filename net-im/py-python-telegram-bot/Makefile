# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-telegram-bot
PORTVERSION=	10.0.1
CATEGORIES=	net-im devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Not just a Python wrapper around the Telegram Bot API

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${FLAVOR}
.endif

.include <bsd.port.post.mk>
