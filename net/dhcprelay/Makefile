# New ports collection makefile for:   dhcprelay
# Date created:        15 November 2005
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	dhcprelay
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Lightweight DHCP Relay Agent with GIF tunnel support

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

PLIST_FILES=	bin/dhcprelay 
USE_RC_SUBR=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcprelay ${PREFIX}/bin

.include <bsd.port.mk>
