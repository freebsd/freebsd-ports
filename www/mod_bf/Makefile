# New ports collection makefile for:	mod_bf
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_bf
PORTVERSION=	0.2
CATEGORIES=	www
MASTER_SITES=	SF/modbf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A brainf*ck module for Apache

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
