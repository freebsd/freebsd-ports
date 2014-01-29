# Created by: Lawrence Stewart <lstewart@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Products.PloneLDAP
PORTVERSION=	1.1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	LDAP/Active Directory support for Plone

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.LDAPMultiPlugins>=1.10:${PORTSDIR}/devel/py-Products.LDAPMultiPlugins \
		${PYTHON_PKGNAMEPREFIX}Products.LDAPUserFolder>=2.9:${PORTSDIR}/devel/py-Products.LDAPUserFolder

DIST_SUBDIR=	zope
USE_PYTHON=	2
USE_PYDISTUTILS=easy_install

NO_STAGE=	yes

.include <bsd.port.mk>
