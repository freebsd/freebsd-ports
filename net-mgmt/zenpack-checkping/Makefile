# New ports collection makefile for: CheckPing
# Date created:    08 June 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	CheckPing
PORTVERSION=	1.0
CATEGORIES=	net-mgmt www
MASTER_SITES=	https://github.com/zenoss/${ZPACKPREFIX}${PORTNAME}/tarball/master/
DISTFILES=	zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides nagios ping check for Zenoss monitoring

ZPACKPREFIX=	ZenPacks.Nagios.
ZPACKGROUP=	community
WRKSRC=	${WRKDIR}/zenoss-${ZPACKPREFIX}${PORTNAME}-${TAG}
TAG=            0088e17

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
