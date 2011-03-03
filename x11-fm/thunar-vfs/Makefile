# New ports collection makefile for: thunar-vfs
# Date created:		2010-11-13
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	thunar-vfs
PORTVERSION=	1.2.0
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The virtual filesystem for Thunar

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gamin-1.1:${PORTSDIR}/devel/gamin

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libutil libexo
USE_XORG=	x11

CONFIGURE_ARGS=	--disable-debug

OPTIONS=	NLS "Enable Native Language Support" on \
		HAL "Enable HAL support" on \
		DBUS "Enable D-BUS support" on \
		STARTUP "Enable startup notification support" on \
		GCONF "Enable GCONF support" off \
		APIDOCS "Install api documentation" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=--with-volume-manager=hal
.else
CONFIGURE_ARGS+=--with-volume-manager=freebsd
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if !defined(WITHOUT_STARTUP)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

# GNOME thumbnailers
.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gnome-thumbnailers
.else
CONFIGURE_ARGS+=--disable-gnome-thumbnailers
.endif

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
