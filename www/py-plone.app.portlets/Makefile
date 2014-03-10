# $FreeBSD$

PORTNAME=	plone.app.portlets
PORTVERSION=	2.4.5
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone integration for the basic plone.portlets package

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.formlib>=0:${PORTSDIR}/devel/py-five.formlib \
		${PYTHON_PKGNAMEPREFIX}five.customerize>=0:${PORTSDIR}/devel/py-five.customerize \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:${PORTSDIR}/www/py-plone.i18n \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=1.1:${PORTSDIR}/www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.form>=0:${PORTSDIR}/www/py-plone.app.form \
		${PYTHON_PKGNAMEPREFIX}plone.app.i18n>=0:${PORTSDIR}/www/py-plone.app.i18n \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=1.2:${PORTSDIR}/www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:${PORTSDIR}/www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:${PORTSDIR}/devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:${PORTSDIR}/devel/py-zope.contentprovider \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:${PORTSDIR}/devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:${PORTSDIR}/devel/py-Products.CMFDynamicViewFTI \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:${PORTSDIR}/security/py-Products.PluggableAuthService \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:${PORTSDIR}/textproc/py-feedparser

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>
