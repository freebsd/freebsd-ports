# New ports collection makefile for:	py-RestrictedPython
# Date created:				10 October, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	RestrictedPython
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	Restricted execution environment for Python

LICENSE=	ZPL21

USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 270
PLIST_SUB+=	PYTHON27=""
.else
PLIST_SUB+=	PYTHON27="@comment "
.endif

.include <bsd.port.post.mk>
