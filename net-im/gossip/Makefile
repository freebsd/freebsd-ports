# New ports collection makefile for:	gossip
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gossip
PORTVERSION=	0.23
CATEGORIES=	net-im gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK2 Jabber Instant Messaging client

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		aspell.16:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomepanel gnomedocutils
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-dbus=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gossip.schemas

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build on 4.X
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--enable-libnotify=no
.endif

.include <bsd.port.post.mk>
