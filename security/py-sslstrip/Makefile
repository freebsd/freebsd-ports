# New ports collection makefile for:	sslstrip
# Date created:		2009-04-17
# Whom:			User & <dragon@njord.localdomain>
#
# $FreeBSD$
#

PORTNAME=	sslstrip
PORTVERSION=	0.9
CATEGORIES=	security python
MASTER_SITES=	http://www.thoughtcrime.org/software/sslstrip/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kitchetech@gmail.com
COMMENT=	Python program for SSL stripping

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	sslstrip
RUN_DEPENDS =	${LOCALBASE}/lib/python2.7/site-packages/twisted/web:${PORTSDIR}/www/py-twistedWeb
.include <bsd.port.mk>
