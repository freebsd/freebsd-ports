# New ports collection makefile for: MACReport
# Date created:    13 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	MACReport
PORTVERSION=	1.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://zenpacks.zenoss.org/trac-zenpacks/changeset/1002/tags/
DISTFILES=	mac-report-${PORTVERSION}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Lists MAC address and the Device and Interface associated info

USE_ZIP=	yes
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/tags/mac-report-${PORTVERSION}

ZPACKPREFIX=	ZenPacks.sodonnell.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
