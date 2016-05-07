# $FreeBSD$

PORTNAME=	plone.formwidget.namedfile
PORTVERSION=	1.0.15
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Image widget for z3c.form and Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile \
		${PYTHON_PKGNAMEPREFIX}z3c.form>0:devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
