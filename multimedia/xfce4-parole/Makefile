# New ports collection makefile for:	Xfce4-parole
# Date created:		26 December 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-parole
PORTVERSION=	0.2.0.6
PORTREVISION=	3
CATEGORIES=	multimedia xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/parole/0.2
DIST_SUBDIR=	xfce4
DISTNAME=	parole-${PORTVERSION}

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on the gstreamer engine

DATADIR=	${PREFIX}/share/${PORTNAME:S/xfce4-//}

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GSTREAMER=	ffmpeg good theora xvid mp3 faad ogg dvd x264 \
		flac wavpack soup
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-power-manager-plugin \
		--enable-libnotify \
		--enable-taglib \
		--disable-gtk-doc-html \
		--without-html-dir
CONFIGURE_ENV=	ac_cv_prog_AWK="${AWK}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack pkgconfig \
		desktopfileutils
USE_XFCE=	configenv libgui libutil
USE_XORG=	x11 sm
USE_LDCONFIG=	yes

OPTIONS=	NLS "Enable Native Language Support" on \
		CDDA "Enable CD audio support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_CDDA)
LIB_DEPENDS+=	cdio++.0:${PORTSDIR}/sysutils/gstreamer-plugins-cdio
USE_GSTREAMER+=	cdaudio
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
