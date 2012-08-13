# New ports collection makefile for:	py-django-sekizai
# Date created:				30 Jan 2012
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$
#

PORTNAME=	django-sekizai
PORTVERSION=	0.6.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Block templating system for Django

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-classy-tags>=0.3.1:${PORTSDIR}/www/py-django-classy-tags

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
