# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vfs
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/archive/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The virtual filesystem for Thunar

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgamin-1.so:${PORTSDIR}/devel/gamin

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 gdkpixbuf2 intltool intlhack
USE_XFCE=	configenv libutil libexo
USE_XORG=	x11
USES=		gmake pathfix perl5 pkgconfig libtool desktop-file-utils \
		tar:bzip2

CONFIGURE_ARGS=	--disable-debug

OPTIONS_DEFINE=	NLS HAL DBUS STARTUP GCONF DOCS
OPTIONS_DEFAULT=	NLS HAL DBUS STARTUP
STARTUP_DESC=	Startup notification

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	libhal.so:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=--with-volume-manager=hal
.else
CONFIGURE_ARGS+=--with-volume-manager=freebsd
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

# GNOME thumbnailers
.if ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=--enable-gnome-thumbnailers
.else
CONFIGURE_ARGS+=--disable-gnome-thumbnailers
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.mk>
