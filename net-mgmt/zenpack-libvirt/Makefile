# New ports collection makefile for: libvirt
# Date created:    20 May 2011
# Whom:      Zenoss <zenoss@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	libvirt
PORTVERSION=	1.71
CATEGORIES=	net-mgmt
MASTER_SITES=	http://zenpacks.zenoss.org/trac-zenpacks/changeset/1002/tags/
DISTFILES=	${PORTNAME}-${PORTVERSION}?old_path=%2F\&format=zip

MAINTAINER=	zenoss@experts-exchange.com
COMMENT=	Provides monitoring of virtualization servers through Zenoss

LICENSE=	GPLv2

RUN_DEPENDS=	libvirt>=0.9.1:${PORTSDIR}/devel/libvirt

WRKSRC=	${WRKDIR}/tags/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
ZPACKPREFIX=	ZenPacks.community.
ZPACKGROUP=	community

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.zenoss.mk"
.include <bsd.port.post.mk>
