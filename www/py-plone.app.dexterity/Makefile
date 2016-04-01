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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>0:devel/py-collective.z3cform.datetimewidget \
		${PYTHON_PKGNAMEPREFIX}plone.app.textfield>0:www/py-plone.app.textfield \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior \
		${PYTHON_PKGNAMEPREFIX}plone.dexterity>0:www/py-plone.dexterity \
		${PYTHON_PKGNAMEPREFIX}plone.formwidget.namedfile>0:www/py-plone.formwidget.namedfile \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822 \
		${PYTHON_PKGNAMEPREFIX}plone.schemaeditor>0:www/py-plone.schemaeditor \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}plone.app.content>0:www/py-plone.app.content \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.app.uuid>0:www/py-plone.app.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>0:www/py-plone.app.z3cform \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform \
		${PYTHON_PKGNAMEPREFIX}plone.contentrules>0:www/py-plone.contentrules \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
