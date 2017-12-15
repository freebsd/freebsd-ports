# Created by: Kyle Evans <kevans@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Flask-Principal
PORTVERSION=	0.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Identity management for flask

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
