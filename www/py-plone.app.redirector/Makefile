# New ports collection makefile for:	py-plone.app.redirector
# Date created:				03 January 2012
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone.app.redirector
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Redirection tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:${PORTSDIR}/www/py-plone.memoize

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
