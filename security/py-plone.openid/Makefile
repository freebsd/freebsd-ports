# $FreeBSD$

PORTNAME=	plone.openid
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	OpenID authentication support for PAS

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-openid>=0:security/py-python-openid \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.PluggableAuthService>=0:security/py-Products.PluggableAuthService \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
