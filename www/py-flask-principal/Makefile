# Created by: Kyle Evans <bsdports@kyle-evans.net>
# $FreeBSD$

PORTNAME=	Flask-Principal
PORTVERSION=	0.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Identity management for flask

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
