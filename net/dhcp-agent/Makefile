# ex:ts=8
# Ports collection makefile for:	dhcp-agent
# Date created:			Oct 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dhcp-agent
PORTVERSION=	0.41
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable UNIX Dynamic Host Configuration suite

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet
LIB_DEPENDS=	guile.18:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

MAN1=	dhcp-client.1 dhcp-sniff.1
INFO=	dhcp-agent

BROKEN=	does not build with guile-1.8
DEPRECATED=	Dhcp-agent has not been updated since 2003, it does \
		not build with guile-1.8, and it is unmaintained
EXPIRATION_DATE=	2008-04-02

.include <bsd.port.mk>
