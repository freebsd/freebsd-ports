# New ports collection makefile for:	py-wsgiref
# Date created:				21 Dec 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wsgiref
PORTVERSION=	0.1.2
CATEGORIES=	www devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/w/wsgiref/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backport of Python 2.5's wsgiref module

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
IGNORE=	hashlib ships with Python 2.5.x
.endif

.include <bsd.port.post.mk>
