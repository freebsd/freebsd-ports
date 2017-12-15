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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>0:devel/py-zope.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>0:devel/py-zope.site@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>0:devel/py-zope.testing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:devel/py-zope.lifecycleevent@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>0:devel/py-Products.DCWorkflow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:devel/py-Products.statusmessages@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
