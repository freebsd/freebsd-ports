# New ports collection makefile for: ApacheMonitor
# Date created:    12 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	ApacheMonitor
PORTVERSION=	2.1.2
CATEGORIES=	net-mgmt www
MASTER_SITES=   http://dev.zenoss.org/trac/changeset/26203/tags/zenoss-3.1.0/zenpacks/
DISTFILES=	${ZPACKPREFIX}${PORTNAME}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides performance monitoring of the Apache HTTP Server
USE_ZIP=	yes
ZPACKGROUP=	core
WRKSRC=		${WRKDIR}/tags/zenoss-3.1.0/zenpacks/${ZPACKPREFIX}${PORTNAME}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
