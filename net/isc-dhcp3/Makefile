# Ports collection makefile for:    dhcp
# Version required:     ISC-DHCP-BETA-0
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.2 1996/02/29 09:22:43 asami Exp $
#

DISTNAME=       DHCPD-BETA-0
PKGNAME=	isc-dhcp-beta0
CATEGORIES+=	net
MASTER_SITES=   ftp://www.isc.org/pub/dhcp/

MAINTAINER=	se@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; $(INSTALL) -c $(STRIP) -o $(BINOWN) -g $(BINGRP) -m $(BINMODE) dhcpd dhclient $(PREFIX)/sbin
	cd ${WRKSRC}; $(INSTALL) -c -o $(MANOWN) -g $(MANGRP) -m $(MANMODE) dhcpd.conf.5${ZEXTENSION} $(PREFIX)/man/man5
	cd ${WRKSRC}; $(INSTALL) -c -o $(MANOWN) -g $(MANGRP) -m $(MANMODE) dhcpd.8${ZEXTENSION} $(PREFIX)/man/man8

.include <bsd.port.mk>
