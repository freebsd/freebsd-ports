# Created by: Kyle Evans <bsdports@kyle-evans.net>
# $FreeBSD$

PORTNAME=	Flask-Assets
PORTVERSION=	0.12
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Asset management for flask

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}webassets>=0:www/py-webassets

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
