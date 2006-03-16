# New ports collection makefile for:    py-mimelib
# Date created:         31 July 2003
# Whom:                 Gerhard Schmidt <estartu@augusta.de>
#
# $FreeBSD$
#

PORTNAME=	email
PORTVERSION=	2.5.7
CATEGORIES=	mail python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/e/email/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	email-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Email package for Python 2.1.3 or upper

NO_LATEST_LINK=	yes
CONFLICTS=	py*-mimelib-3.* py*-email-3.*

DIST_SUBDIR=	python
USE_PYTHON=	-2.2
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
