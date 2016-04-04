# $FreeBSD$

PORTNAME=	plone.folder
PORTVERSION=	1.0.7
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	BTree-based folder implementation with order support

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}Products.BTreeFolder2>0:devel/py-Products.BTreeFolder2 \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>0:devel/py-Products.ZCatalog \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:devel/py-zope.container

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
