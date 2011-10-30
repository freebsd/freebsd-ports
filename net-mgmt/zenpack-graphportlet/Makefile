# New ports collection makefile for: ShowGraphPortlet
# Date created:    12 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	ShowGraphPortlet
PORTVERSION=	1.03
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://zenpacks.zenoss.org/trac-zenpacks/changeset/1002/tags/
DISTFILES=	graph-portlet-${PORTVERSION}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Enables users to show any graph/multi graph reports on their dashboard

USE_ZIP=	yes
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/tags/graph-portlet-${PORTVERSION}/

ZPACKPREFIX=	ZenPacks.SCC.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
