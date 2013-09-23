# $FreeBSD$

PORTNAME=	plone.app.z3cform
PORTVERSION=	0.7.4
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Collection of widgets, templates for use with z3c.form and Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>=0.1:${PORTSDIR}/devel/py-collective.z3cform.datetimewidget \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0.5.11:${PORTSDIR}/www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}plone.protect>0:${PORTSDIR}/security/py-plone.protect \
		${PYTHON_PKGNAMEPREFIX}z3c.formwidget.query>0:${PORTSDIR}/devel/py-z3c.formwidget.query \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:${PORTSDIR}/devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:${PORTSDIR}/devel/py-zope.traversing

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes
USE_ZOPE=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
