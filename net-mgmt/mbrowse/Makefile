# New ports collection makefile for:	mbrowse
# Date created:			Apr 4, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mbrowse
PORTVERSION=	0.3.1
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kill-9.org/mbrowse/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SNMP MIB Browser for X

LIB_DEPENDS=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mbrowse
USE_GNOME=	gtk12 gnometarget
CONFIGURE_ARGS=	--with-snmp-prefix=${PREFIX} --with-snmp-type=net
CONFIGURE_ENV=	LDFLAGS="`net-snmp-config --libs`" \
		CPPFLAGS="`net-snmp-config --cflags`"

.include <bsd.port.mk>
