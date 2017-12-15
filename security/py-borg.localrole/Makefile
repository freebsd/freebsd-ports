# $FreeBSD$

PORTNAME=	borg.localrole
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	PAS plugin which can manage local roles via an adapter lookup

LICENSE=	LGPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>=0:security/py-Products.PlonePAS@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
