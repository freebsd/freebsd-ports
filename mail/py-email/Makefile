# New ports collection makefile for:    py-mimelib
# Date created:         31 July 2003
# Whom:                 Gerhard Schmidt <estartu@augusta.de>
#
# $FreeBSD$
#

PORTNAME=	email
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/e/email/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	email-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Email package for Python 2.3 or upper

DEPRECATED=	Included into all supported python versions
EXPIRATION_DATE=	2012-03-14

DIST_SUBDIR=	python
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

CONFLICTS=	py*-mimelib-2.* py*-email-2.*

.include <bsd.port.mk>
