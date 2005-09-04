# New ports collection makefile for:    py-mimelib
# Date created:         31 July 2003
# Whom:                 Gerhard Schmidt <estartu@augusta.de>
#
# $FreeBSD$
#

PORTNAME=	email
PORTVERSION=	2.5.6
CATEGORIES=	mail python
MASTER_SITES=	ftp://ftp.python.org/pub/python/contrib/
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
DISTNAME=       email-${PORTVERSION}

MAINTAINER=	estartu@augusta.de
COMMENT=	Email package for Python 2.1.3 or upper

NO_LATEST_LINK=	yes
CONFLICTS=	py*-mimelib-3.* py*-email-3.*

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 230
IGNORE=		For your Python version use ${PORTSDIR}/mail/${PORTNAME}
.endif

.include <bsd.port.post.mk>
