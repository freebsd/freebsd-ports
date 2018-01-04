# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-sekizai
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Block templating system for Django

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-classy-tags>=0.3.1:www/py-django-classy-tags@${FLAVOR}

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
