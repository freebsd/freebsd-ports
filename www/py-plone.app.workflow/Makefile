# $FreeBSD$

PORTNAME=	plone.app.workflow
PORTVERSION=	2.1.9
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Workflow and security settings for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}transaction>0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>0:devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}Acquisition>0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>0:devel/py-Products.DCWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:devel/py-Products.statusmessages

NO_ARCH=	yes
USES=		python zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
