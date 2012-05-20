# New ports collection makefile for:	py-plone.app.ldap
# Date created:				20 May 2012
# Whom:					Lawrence Stewart <lstewart@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	plone.app.ldap
PORTVERSION=	1.2.8
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP control panel for Plone 3 and Plone 4

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.1.0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.PloneLDAP>=1.0:${PORTSDIR}/www/py-Products.PloneLDAP

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
