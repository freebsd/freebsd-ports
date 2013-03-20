# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	django-tastypie
PORTVERSION=	0.9.13
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	william88@gmail.com
COMMENT=	Create REST API for Django apps

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mimeparse>=0:${PORTSDIR}/devel/py-mimeparse \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}rose>=1:${PORTSDIR}/devel/py-rose

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
