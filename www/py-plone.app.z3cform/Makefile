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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>=0.1:devel/py-collective.z3cform.datetimewidget \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0.5.11:www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}plone.protect>0:security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}z3c.formwidget.query>0:devel/py-z3c.formwidget.query \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:devel/py-zope.traversing

NO_ARCH=	yes
USES=		python zip zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
