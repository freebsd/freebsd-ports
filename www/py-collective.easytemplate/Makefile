# Created by: Michelle Sullivan <michelle@sorbs.net>
# $FreeBSD$

PORTNAME=	collective.easytemplate
PORTVERSION=	0.8.0
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	michelle@sorbs.net
COMMENT=	Dynamic HTML generation and scripting for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.1.0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.7.3:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.portlet.static>=0:www/py-plone.portlet.static@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}collective.templateengines>=0.3:www/py-collective.templateengines@${FLAVOR}

USES=		python:2 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
