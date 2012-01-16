# New ports collection makefile for:	py-plone.app.blob
# Date created:				02 January 2012
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone.app.blob
PORTVERSION=	1.5.1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZODB blob support for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=3.8.1:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=3.4:${PORTSDIR}/net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}archetypes.schemaextender>=1.6:${PORTSDIR}/devel/py-archetypes.schemaextender \
		${PYTHON_PKGNAMEPREFIX}plone.app.imaging>1.0:${PORTSDIR}/www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.scale>=0:${PORTSDIR}/www/py-plone.scale

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
