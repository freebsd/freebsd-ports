# New ports collection makefile for:	mod_rpaf
# Date created:				Mar 17, 2003
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_rpaf
PORTVERSION=	0.6
CATEGORIES=	www
MASTER_SITES=	http://stderr.net/apache/rpaf/download/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Make proxied requests appear with client IP

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	2012-01-01

MAKE_JOBS_SAFE=  yes

USE_APACHE?=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
SRC_FILE=	mod_rpaf-2.0.c
.endif

.include <bsd.port.post.mk>
