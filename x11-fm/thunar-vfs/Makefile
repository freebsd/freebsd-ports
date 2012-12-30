# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	thunar-vfs
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	x11-fm xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/archive/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	The virtual filesystem for Thunar

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2 \
		gamin-1:${PORTSDIR}/devel/gamin

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libutil libexo
USE_XORG=	x11
USE_PKGCONFIG=	build

CONFIGURE_ARGS=	--disable-debug

OPTIONS_DEFINE=	NLS HAL DBUS STARTUP GCONF APIDOCS
OPTIONS_DEFAULT=	NLS HAL DBUS STARTUP APIDOCS

APIDOCS_DESC=	Install api documentation
STARTUP_DESC=	Enable startup notification support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=--with-volume-manager=hal
.else
CONFIGURE_ARGS+=--with-volume-manager=freebsd
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	startup-notification-1:${PORTSDIR}/x11/startup-notification
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

.if ${PORT_OPTIONS:MAPIDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
