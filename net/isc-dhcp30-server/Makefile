# Ports collection makefile for:    dhcp
# Version required:     ISC-DHCP-BETA-16
# Date created:         7 Mar 1996
# Whom:                 se
#
# $Id: Makefile,v 1.9 1997/06/03 06:47:59 asami Exp $
#

DISTNAME=       DHCPD-BETA-5.16
PKGNAME=	isc-dhcp-b5.16
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.isc.org/isc/dhcp/

MAINTAINER=	ports@FreeBSD.org

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=		"currently doesn't compile for -current"
.endif

HAS_CONFIGURE=	yes

MAN5=		dhcpd.conf.5
MAN8=		dhcpd.8

.include <bsd.port.mk>
