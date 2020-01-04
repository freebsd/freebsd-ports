# $FreeBSD$

PORTNAME=	Products.PluggableAuthService
PORTVERSION=	1.11.0
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Pluggable Zope2 authentication / authorization framework

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.PluginRegistry>=0:devel/py-Products.PluginRegistry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
