# New ports collection makefile for:   dhcprelay
# Date created:        15 November 2005
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	dhcprelay
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Lightweight DHCP Relay Agent with GIF tunnel support

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

PLIST_FILES=	bin/dhcprelay etc/rc.d/dhcprelay.sh
USE_RC_SUBR=	yes
SUB_FILES=	dhcprelay.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcprelay ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/dhcprelay.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
