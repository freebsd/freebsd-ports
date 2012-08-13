# New ports collection makefile for:	py-django-cms
# Date created:				30 Jan 2012
# Whom:					Matthew X. Economou <xenophon+fbsdports@irtnog.org>
#
# $FreeBSD$
#

PORTNAME=	django-cms
PORTVERSION=	2.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	Content management system built with the Django framework

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.7.3:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}django>=1.3.1:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-classy-tags>=0.3.4.1:${PORTSDIR}/www/py-django-classy-tags \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.4.2:${PORTSDIR}/www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}django-sekizai>=0.6.1:${PORTSDIR}/www/py-django-sekizai \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.90:${PORTSDIR}/www/py-html5lib

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
