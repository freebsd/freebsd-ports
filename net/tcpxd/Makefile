# New ports collection makefile for:	tcpxd
# Date created:		2006-10-29
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	tcpxd
PORTVERSION=	1.4
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://quozl.us.netrek.org/tcpxd/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose TCP/IP relay

HAS_CONFIGURE=	yes

PLIST_FILES=	sbin/tcpxd etc/tcpxd.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpxd ${PREFIX}/sbin
	${INSTALL_DATA}  ${WRKSRC}/tcpxd.conf ${PREFIX}/etc/tcpxd.conf

.include <bsd.port.mk>
