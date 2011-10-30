# New ports collection makefile for: DellMonitor
# Date created:    05 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	DellMonitor
PORTVERSION=	2.1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dev.zenoss.org/trac/changeset/26194/tags/zenoss-3.1.0/zenpacks/
DISTFILES=	${ZPACKPREFIX}${PORTNAME}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides Zenoss monitoring options for Dell machines

USE_ZIP=	yes
ZPACKGROUP=	core
WRKSRC=	        ${WRKDIR}/tags/zenoss-3.1.0/zenpacks/${ZPACKPREFIX}${PORTNAME}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
