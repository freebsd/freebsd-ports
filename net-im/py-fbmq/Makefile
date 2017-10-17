# $FreeBSD$

PORTNAME=	fbmq
PORTVERSION=	2.3.1
CATEGORIES=	net-im devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Python library for using the Facebook Messenger API

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
