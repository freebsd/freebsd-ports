# New ports collection makefile for:	Xfce4-parole
# Date created:		26 December 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	parole
PORTVERSION=	0.2.0.6
PORTREVISION=	5
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/src/apps/parole/0.2/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on gstreamer

LICENSE=	GPLv2

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GSTREAMER=	core faad flac wavpack
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-power-manager-plugin \
		--enable-libnotify \
		--enable-taglib \
		--without-html-dir
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack pkgconfig \
		desktopfileutils
USE_XFCE=	configenv libgui libutil
USE_XORG=	x11 sm
USE_LDCONFIG=	yes

OPTIONS=	CDDA	"CD audio support (cdparanoia)"		on	\
		HTTP	"HTTP streaming support (libsoup)"	on	\
		NLS	"Native Language Support"		on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_CDDA)
USE_GSTREAMER+=	cdparanoia
.endif

.if !defined(WITHOUT_HTTP)
USE_GSTREAMER+=	soup
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
