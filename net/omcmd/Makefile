# Created by: Pavel Volkov
# $FreeBSD$

PORTNAME=	omcmd
PORTVERSION=	0.4.8
CATEGORIES=	net
MASTER_SITES=	http://people.bridgewater.edu/~dparsley/omcmd/

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	CLI utility for performing OMAPI queries and updates on a ISC DHCP

DEPRECATED=	Unfetchable and depends on expired net/isc-dhcp41-server
EXPIRATION_DATE=2016-06-01

BUILD_DEPENDS=	${LOCALBASE}/sbin/dhcpd:net/isc-dhcp41-server

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
