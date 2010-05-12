# New ports collection makefile for:	mod_remoteip
# Date created:		2010-05-11
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	mod_remoteip
PORTVERSION=	2.3.5.a
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-2.3.5-alpha

MAINTAINER=	ports@christianserving.org
COMMENT=	Replaces the client IP address/hostname with that given by a proxy

USE_APACHE=	2.2+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

SRC_FILE=	modules/metadata/${PORTNAME}.c

.include <bsd.port.mk>
