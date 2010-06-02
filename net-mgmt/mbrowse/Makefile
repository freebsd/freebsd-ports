# New ports collection makefile for:	mbrowse
# Date created:			Apr 4, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mbrowse
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	eg@fbsd.lt
COMMENT=	An SNMP MIB Browser for X

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mbrowse
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-snmp-prefix=${PREFIX} --with-snmp-type=net
CONFIGURE_ENV=	LDFLAGS="`net-snmp-config --libs`" \
		CPPFLAGS="`net-snmp-config --cflags`"

.include <bsd.port.mk>
