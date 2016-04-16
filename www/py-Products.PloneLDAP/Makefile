# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.PloneLDAP
PORTVERSION=	1.2
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP/Active Directory support for Plone

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>0:security/py-Products.PlonePAS \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPMultiPlugins>=1.10:devel/py-Products.LDAPMultiPlugins \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:devel/py-Products.LDAPUserFolder

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
