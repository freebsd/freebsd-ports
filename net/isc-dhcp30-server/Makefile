# Ports collection makefile for:    dhcp
# Version required:     ISC-DHCP-BETA-0
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.1 1996/03/08 11:45:10 se Exp $
#

DISTNAME=       DHCPD-BETA-0
PKGNAME=	isc-dhcp-b0
CATEGORIES+=	net
MASTER_SITES=   ftp://www.isc.org/pub/dhcp/

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
