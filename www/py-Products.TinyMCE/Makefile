# $FreeBSD$

PORTNAME=	Products.TinyMCE
PORTVERSION=	1.3.19
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adds support for TinyMCE to Plone

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.imaging>=1.0.2:www/py-plone.app.imaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:www/py-plone.outputfilters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:www/py-plone.app.layout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.caching>0:www/py-plone.caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>0:devel/py-Products.ResourceRegistries@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>0:devel/py-zope.app.content@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 shebangfix zip
USE_PYTHON=	autoplist distutils

python_OLD_CMD=	/opt/local/bin/python2.4
SHEBANG_FILES=	Products/TinyMCE/utils/generate-po.py \
		Products/TinyMCE/utils/compile-mo.py

.include <bsd.port.mk>
