# ex:ts=8
# Ports collection makefile for:	dhcp-agent
# Date created:			Oct 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dhcp-agent
PORTVERSION=	0.41
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable UNIX Dynamic Host Configuration suite

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

MAN1=	dhcp-client.1 dhcp-sniff.1
INFO=	dhcp-agent

.include <bsd.port.mk>
