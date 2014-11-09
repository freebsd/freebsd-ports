# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	mod_remoteip
PORTVERSION=	2.3.5.a
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-2.3.5-alpha

MAINTAINER=	ports@christianserving.org
COMMENT=	Replaces the client IP address/hostname with that given by a proxy

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

SRC_FILE=	modules/metadata/${PORTNAME}.c

.include <bsd.port.mk>
