# New ports collection makefile for:	gaim
# Date created:			26 Mar 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/pidgin/Makefile,v 1.17 2007/09/17 19:53:06 marcus Exp $
#

PORTNAME=	pidgin
PORTREVISION=	0

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Pidgin multi-protocol messaging client (GTK+ UI)

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		purple.3:${PORTSDIR}/net-im/libpurple

MASTERDIR=	${.CURDIR}/../libpurple
BUILD_WRKSRC=	${WRKSRC}/pidgin
INSTALL_WRKSRC=	${BUILD_WRKSRC}
INSTALLS_ICONS=	yes
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PIDGIN_SLAVE=	yes
WITH_GTKUI=	yes

USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20
WANT_GNOME=	yes
CONFIGURE_ARGS=	--disable-consoleui

.include "${MASTERDIR}/Makefile"
