# Ports collection makefile for:	knowlan
# Date Created:			2003-10-27
# Whom:				Omer Faruk Sen <ofsen@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	knowlan
PORTVERSION=	0.1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.enderunix.org/knowlan/

MAINTAINER=	ofsen@enderunix.org
COMMENT=	ARP-based LAN IP and MAC Address Extractor

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/knowlan ${PREFIX}/sbin

.include <bsd.port.mk>
