# Created by: John Hixson <john@ixsystems.com>
# $FreeBSD$

PORTNAME=	django-simple-captcha
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@ixsystems.com
COMMENT=	Simple, yet powerful, Django captcha application

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.3:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.0.0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}six>=1.2.0:devel/py-six

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
