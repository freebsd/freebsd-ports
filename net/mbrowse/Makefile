# New ports collection makefile for:	mbrowse
# Date created:			Apr 4, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mbrowse
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.kill-9.org/mbrowse/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	An SNMP MIB Browser for X

.if defined(WITH_NET_SNMP4)
LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp4
.else
LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net/net-snmp
.endif

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mbrowse
USE_GNOME=	gtk12
CONFIGURE_ARGS+=	--with-snmp-prefix=${LOCALBASE}

.if defined(WITH_NET_SNMP4)
CONFIGURE_ARGS+=	--with-snmp-type=ucd
.else
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-snmp-type=net
.endif

.include <bsd.port.mk>
