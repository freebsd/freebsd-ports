# $FreeBSD$

PORTNAME=	plone.app.dexterity
PORTVERSION=	2.0.17
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Flexible CMF content

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>0:devel/py-collective.z3cform.datetimewidget@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.textfield>0:www/py-plone.app.textfield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.dexterity>0:www/py-plone.dexterity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.formwidget.namedfile>0:www/py-plone.formwidget.namedfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.schemaeditor>0:www/py-plone.schemaeditor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.content>0:www/py-plone.app.content@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:www/py-plone.app.layout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.uuid>0:www/py-plone.app.uuid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>0:www/py-plone.app.z3cform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.contentrules>0:www/py-plone.contentrules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>0:www/py-plone.portlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>0:devel/py-Products.GenericSetup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
