# New ports collection makefile for:	pptpclient
# Date created:		19 June 1999
# Whom:			John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pptpclient
PORTVERSION=	1.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.pdos.lcs.mit.edu/~cananian/Projects/PPTP/release/ \
		ftp://ftp.kddlabs.co.jp/pub/inet/vpn/pptp-linux/ \
		ftp://ftp.iks-jena.de/pub/software/linux/net/
DISTNAME=	pptp-linux-1.0.2

MAINTAINER=	jdp@freebsd.org

post-install:
	${MKDIR} ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/examples/pptpclient
	${INSTALL_DATA} ${FILESDIR}/ppp.conf ${PREFIX}/share/examples/pptpclient

.include <bsd.port.mk>
