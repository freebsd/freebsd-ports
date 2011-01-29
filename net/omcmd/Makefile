# New ports collection makefile for:	omcmd
# Date created:				05 Jul 2010
# Whom:					Pavel Volkov
#
# $FreeBSD$
#

PORTNAME=	omcmd
PORTVERSION=	0.4.8
CATEGORIES=	net
MASTER_SITES=	http://people.bridgewater.edu/~dparsley/omcmd/

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	CLI utility for performing OMAPI queries and updates on a ISC DHCP

BUILD_DEPENDS=	${LOCALBASE}/sbin/dhcpd:${PORTSDIR}/net/isc-dhcp41-server

PLIST_FILES=	bin/${PORTNAME}

MAN1=	${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
