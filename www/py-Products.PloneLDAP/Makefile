# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.PloneLDAP
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP/Active Directory support for Plone

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.LDAPMultiPlugins>=1.10:devel/py-Products.LDAPMultiPlugins \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:devel/py-Products.LDAPUserFolder

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
