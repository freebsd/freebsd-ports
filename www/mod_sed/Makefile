# ex:ts=8
# New ports collection makefile for:	mod_sed
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mod_sed
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	http://www.happygiraffe.net/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An apache module that embeds a copy of the sed(1) command

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=	yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.mk>
