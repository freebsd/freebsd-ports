# New ports collection makefile for:	dhcpd-pools
# Date created:		26 January 2012
# Whom:			Ryan Steinmetz (zi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	dhcpd-pools
PORTVERSION=	2.16
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A tool to analyze isc-dhcp pool usage based on leases

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dhcpd-conf=${LOCALBASE}/etc/dhcpd.conf \
		--with-dhcpd-leases=/var/db/dhcpd/dhcpd.leases

PLIST_FILES=	bin/dhcpd-pools
PORTDATA=	dhcpd-pools.cgi snmptest.pl

MAN1=		dhcpd-pools.1

post-patch:
	@${REINPLACE_CMD} -e '/features.h/d' ${WRKSRC}/src/getdata.c

.include <bsd.port.mk>
