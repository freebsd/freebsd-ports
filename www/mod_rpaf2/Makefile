# New ports collection makefile for:	mod_rpaf2
# Date created:				Mar 17, 2003
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_rpaf2
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://stderr.net/apache/rpaf/download/
DISTNAME=	mod_rpaf-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Make proxied requests appear with client IP

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

SRC_FILE=	mod_rpaf-2.0.c

.include <bsd.port.mk>
