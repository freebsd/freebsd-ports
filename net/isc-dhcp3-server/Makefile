# Ports collection makefile for:    dhcp
# Version required:     2.0b1pl1
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.17 1998/05/23 20:03:52 jseger Exp $
#

DISTNAME=       dhcp-2.0b1pl1
PKGNAME=	isc-dhcp2.b1.1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.isc.org/isc/dhcp/

MAINTAINER=	jseger@FreeBSD.org

HAS_CONFIGURE=	yes

CAT5=		dhclient.conf.5 dhclient.leases.5 dhcp-options.5 dhcpd.conf.5 \
		dhcpd.leases.5
CAT8=		dhclient.8 dhclient-script.8 dhcpd.8 dhcrelay.8

_MANPAGES+=	${CAT5:S%^%${MANPREFIX}/man/cat5/%}
_MANPAGES+=	${CAT8:S%^%${MANPREFIX}/man/cat8/%}

post-install:
	${TOUCH} /var/db/dhcpd.leases
.for file in dhclient dhcpd dhcrelay
	if [ -f ${PREFIX}/sbin/${file} ]; then \
		strip ${PREFIX}/sbin/${file}; \
	fi
.endfor

.include <bsd.port.mk>
