# New ports collection makefile for:	py-plone.app.z3cform
# Date created:				03 January 2012
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	plone.app.z3cform
PORTVERSION=	0.5.7
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Collection of widgets, templates for use with z3c.form and Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0.5.11:${PORTSDIR}/www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}kss-core>=0:${PORTSDIR}/devel/py-kss-core \
		${PYTHON_PKGNAMEPREFIX}plone.app.kss>=0:${PORTSDIR}/www/py-plone.app.kss \
		${PYTHON_PKGNAMEPREFIX}z3c.formwidget.query>=0:${PORTSDIR}/devel/py-z3c.formwidget.query \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}collective.z3cform.datetimewidget>=0.1:${PORTSDIR}/devel/py-collective.z3cform.datetimewidget

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes
#USE_ZOPE=	yes

.include <bsd.port.mk>
