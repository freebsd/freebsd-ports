# New ports collection makefile for:	py-plone.locking
# Date created:				25 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone.locking
PORTVERSION=	2.0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	WebDAV locking support

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:${PORTSDIR}/devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
#USE_ZOPE	yes

.include <bsd.port.mk>
