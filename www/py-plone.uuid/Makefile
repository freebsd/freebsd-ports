# New ports collection makefile for:	py-plone.uuid
# Date created:				25 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone.uuid
PORTVERSION=	1.0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	UUIDs for content items

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:${PORTSDIR}/devel/py-zope.app.publisher

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
