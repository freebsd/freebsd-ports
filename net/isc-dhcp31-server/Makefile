# Ports collection makefile for:    dhcp
# Version required:     ISC-DHCP-BETA-0
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.2 1996/03/09 23:50:05 asami Exp $
#

DISTNAME=       DHCPD-BETA-0
PKGNAME=	isc-dhcp-b0
CATEGORIES+=	net
MASTER_SITES=   ftp://ftp.vix.com/pub/dhcp/

MAINTAINER=	se@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; $(INSTALL) -c $(STRIP) -o $(BINOWN) -g $(BINGRP) -m $(BINMODE) dhcpd dhclient $(PREFIX)/sbin
	cd ${WRKSRC}; $(INSTALL) -c -o $(MANOWN) -g $(MANGRP) -m $(MANMODE) dhcpd.conf.5${ZEXTENSION} $(PREFIX)/man/man5
	cd ${WRKSRC}; $(INSTALL) -c -o $(MANOWN) -g $(MANGRP) -m $(MANMODE) dhcpd.8${ZEXTENSION} $(PREFIX)/man/man8
.if !defined(NOMANCOMPRESS)
	gzip -9nf $(PREFIX)/man/man5/dhcpd.conf.5${ZEXTENSION}
	gzip -9nf $(PREFIX)/man/man8/dhcpd.8${ZEXTENSION}
.endif

.include <bsd.port.mk>
