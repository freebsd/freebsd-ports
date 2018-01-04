# $FreeBSD$

PORTNAME=	plone.app.dexterity
PORTVERSION=	2.0.17
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Flexible CMF content

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>0:devel/py-collective.z3cform.datetimewidget@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.textfield>0:www/py-plone.app.textfield@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.dexterity>0:www/py-plone.dexterity@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.formwidget.namedfile>0:www/py-plone.formwidget.namedfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.schemaeditor>0:www/py-plone.schemaeditor@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.content>0:www/py-plone.app.content@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:www/py-plone.app.layout@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.uuid>0:www/py-plone.app.uuid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>0:www/py-plone.app.z3cform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.contentrules>0:www/py-plone.contentrules@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>0:www/py-plone.portlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
