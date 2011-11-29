# New ports collection makefile for:	tcpxd
# Date created:		2006-10-29
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	tcpxd
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://fossies.org/unix/privat/ \
		http://www.sourcefiles.org/Networking/Tools/Proxy/ \
		http://quozl.us.netrek.org/tcpxd/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	General purpose TCP/IP relay

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tcpxd ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/tcpxd.conf ${PREFIX}/etc/tcpxd.conf.dist

.include <bsd.port.mk>
