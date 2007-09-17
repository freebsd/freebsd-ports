# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/net-im/gaim-devel/Makefile,v 1.3 2006/10/29 18:55:29 marcus Exp $
#

PORTNAME=	pidgin
PORTREVISION=	0

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Pidgin multi-protocol messaging client (GTK+ UI)

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
    		purple.2:${PORTSDIR}/net-im/libpurple

MASTERDIR=	${.CURDIR}/../libpurple
BUILD_WRKSRC=	${WRKSRC}/pidgin
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PIDGIN_SLAVE=	yes
WITH_GTKUI=	yes

USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20
WANT_GNOME=	yes
CONFIGURE_ARGS=	--disable-consoleui

.include "${MASTERDIR}/Makefile"
