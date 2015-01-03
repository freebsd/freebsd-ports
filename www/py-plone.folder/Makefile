# $FreeBSD$

PORTNAME=	plone.folder
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	BTree-based folder implementation with order support

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.memoize>0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:${PORTSDIR}/devel/py-zope.container

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
