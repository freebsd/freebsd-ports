PORTNAME=	mate-control-center
PORTVERSION=	1.28.1
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	sysutils mate
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for MATE project
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		yelp-tools>0:textproc/yelp-tools \
 		yelp-xsl>0:textproc/yelp-xsl
LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libxklavier.so:x11/libxklavier \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libstartup-notification-1.so:x11/startup-notification \
		libunique-3.0.so:x11-toolkits/libunique3 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libaccountsservice.so:sysutils/accountsservice \
		libudisks2.so:sysutils/libudisks

PORTSCOUT=	limitw:1,even

USES=		autoreconf desktop-file-utils gettext gmake gnome libtool localbase mate \
		pathfix pkgconfig shared-mime-info tar:xz xorg
USE_GITHUB=	yes
GH_ACCOUNT=	mate-desktop
USE_CSTD=	c99
USE_MATE=	desktop libmatekbd marco menus settingsdaemon
USE_XORG=	ice sm x11 xcursor xext xft xi xrandr xscrnsaver
USE_GNOME=	cairo dconf glib20 gtk30 intlhack libxml2 librsvg2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-appindicator=no \
		--disable-update-mimedb \
		--disable-systemd
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.control-center.gschema.xml \
		org.mate.control-center.keybinding.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/capplets/common/mate-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.mate.randr.policy.in

.include <bsd.port.mk>
