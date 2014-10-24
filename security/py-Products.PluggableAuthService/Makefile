# $FreeBSD$

PORTNAME=	Products.PluggableAuthService
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Pluggable Zope2 authentication / authorization framework

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.PluginRegistry>=0:${PORTSDIR}/devel/py-Products.PluginRegistry \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup

USES=		python:2 zope
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
