# New ports collection makefile for:    py-mimelib
# Date created:         31 July 2003
# Whom:                 Gerhard Schmidt <estartu@augusta.de>
#
# $FreeBSD$
#

PORTNAME=	mimelib
PORTVERSION=	2.5
CATEGORIES=	mail python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=     mimelib
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
DISTNAME=       email-${PORTVERSION}

MAINTAINER=	estartu@augusta.de
COMMENT=	Email package for Python

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 220
IGNORE=		is part of the Python base distribution since python 2.2
.endif

.include <bsd.port.post.mk>
