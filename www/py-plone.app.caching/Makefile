# $FreeBSD$

PORTNAME=	plone.app.caching
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone UI and default rules for plone.caching/z3c.caching

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}plone.caching>=0:${PORTSDIR}/www/py-plone.caching \
		${PYTHON_PKGNAMEPREFIX}plone.cachepurging>=0:${PORTSDIR}/www/py-plone.cachepurging \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.0:${PORTSDIR}/www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>0:${PORTSDIR}/devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:${PORTSDIR}/devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.protect>=0:${PORTSDIR}/security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=1.0:${PORTSDIR}/www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:${PORTSDIR}/devel/py-Products.CMFDynamicViewFTI \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:${PORTSDIR}/devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>=0:${PORTSDIR}/www/py-plone.app.z3cform \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:${PORTSDIR}/devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}z3c.zcmlhook>=0:${PORTSDIR}/devel/py-z3c.zcmlhook

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>
