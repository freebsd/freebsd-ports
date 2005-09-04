# New ports collection makefile for:    py-mimelib
# Date created:         31 July 2003
# Whom:                 Gerhard Schmidt <estartu@augusta.de>
#
# $FreeBSD$
#

PORTNAME=	email
PORTVERSION=	3.0
CATEGORIES=	mail python
MASTER_SITES=	ftp://ftp.python.org/pub/python/contrib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	email-${PORTVERSION}

MAINTAINER=	estartu@augusta.de
COMMENT=	Email package for Python 2.3 or upper

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

CONFLICTS=	py*-mimelib-2.* py*-email-2.*

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 240
IGNORE=		Python 2.4 or upper don't need this port
.else
.if ${PYTHON_REL} < 230
IGNORE=		For your Python version use ${PORTSDIR}/mail/${PORTNAME}2
.endif
.endif

.include <bsd.port.post.mk>
