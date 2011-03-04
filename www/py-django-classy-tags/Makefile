# New ports collection makefile for:	py-classy-tags
# Date created:				15 Feb 2011
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django-classy-tags
PORTVERSION=	0.3.3
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Class based template tags for Django

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
