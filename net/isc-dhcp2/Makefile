# Ports collection makefile for:    dhcp
# Version required:     ISC-DHCP-BETA-0
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.3 1996/08/27 10:23:06 torstenb Exp $
#

DISTNAME=       DHCPD-BETA-0
PKGNAME=	isc-dhcp-b0
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.vix.com/pub/dhcp/

MAINTAINER=	se@FreeBSD.ORG

MAN5=		dhcpd.conf.5${ZEXTENSION}
MAN8=		dhcpd.8${ZEXTENSION}

do-install:
	cd ${WRKSRC}; $(INSTALL_PROGRAM) dhcpd dhclient $(PREFIX)/sbin
	cd ${WRKSRC}; $(INSTALL_MAN) dhcpd.conf.5${ZEXTENSION} $(PREFIX)/man/man5
	cd ${WRKSRC}; $(INSTALL_MAN) dhcpd.8${ZEXTENSION} $(PREFIX)/man/man8

.include <bsd.port.mk>
