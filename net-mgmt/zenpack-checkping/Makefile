# New ports collection makefile for: CheckPing
# Date created:    08 June 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	CheckPing
PORTVERSION=	1.0
CATEGORIES=	net-mgmt www
MASTER_SITES=	http://zenpacks.zenoss.org/trac-zenpacks/changeset/1002/tags/
DISTFILES=	nagios-check-ping-${PORTVERSION}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides nagios ping check for Zenoss monitoring

USE_ZIP=	yes
ZPACKPREFIX=	ZenPacks.Nagios.
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/tags/nagios-check-ping-${PORTVERSION}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
