# New ports collection makefile for:	mod_hosts_access
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_hosts_access
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	http://www.klomp.org/mod_hosts_access/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that makes Apache respect hosts.allow and hosts.deny

MAKE_JOBS_SAFE=	yes

USE_APACHE=	1.3+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_LIB+=	${LOCALBASE}/lib -lwrap

.include <bsd.port.mk>
