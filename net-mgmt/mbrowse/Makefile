# New ports collection makefile for:	mbrowse
# Date created:			Apr 4, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mbrowse
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kill-9.org/mbrowse/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	An SNMP MIB Browser for X

.if defined(WITH_NET_SNMP4)
LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.else
LIB_DEPENDS=	netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp
.endif

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mbrowse
USE_GNOME=	gtk12 gnometarget
CONFIGURE_ARGS+=	--with-snmp-prefix=${PREFIX} 

.if defined(WITH_NET_SNMP4)
CONFIGURE_ARGS+=	--with-snmp-type=ucd
.else
CONFIGURE_ENV+=		LDFLAGS="`net-snmp-config --libs`" \
			CPPFLAGS="`net-snmp-config --cflags`"
CONFIGURE_ARGS+=	--with-snmp-type=net
.endif

.include <bsd.port.mk>
