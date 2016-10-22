# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	django-tastypie
PORTVERSION=	0.13.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER?=	wg@FreeBSD.org
COMMENT=	Create REST API for Django apps

LICENSE=	BSD3CLAUSE

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.4:devel/py-mimeparse \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1:devel/py-dateutil

BUILD_DEPENDS=	${MY_DEPENDS}

RUN_DEPENDS?=	${MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}django18>=1.5:www/py-django18

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS_INSTALL=	 ${PKGNAMEPREFIX}${PORTNAME}16

.include <bsd.port.mk>
