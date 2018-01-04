# $FreeBSD$

PORTNAME=	plone.app.z3cform
PORTVERSION=	0.7.7
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Collection of widgets, templates for use with z3c.form and Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>=0.1:devel/py-collective.z3cform.datetimewidget@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0.5.11:www/py-plone.z3cform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.protect>0:security/py-plone.protect@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3c.formwidget.query>0:devel/py-z3c.formwidget.query@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:devel/py-zope.traversing@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
