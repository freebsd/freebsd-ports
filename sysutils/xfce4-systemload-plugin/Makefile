PORTNAME=	xfce4-systemload-plugin
PORTVERSION=	1.3.1
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	System Load plugin for Xfce4 panel

LICENSE=	BSD2CLAUSE

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	panel

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-libgtop
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS UPOWER # LIBGTOP
OPTIONS_DEFAULT=	UPOWER
OPTIONS_SUB=		yes

# Enabling libgtop causes crashes, needs investigation
#LIBGTOP_DESC=		Use libgtop for network utilization monitoring
UPOWER_DESC=		Use upower for adapting update interval to power state

#LIBGTOP_CONFIGURE_ENABLE=	libgtop
#LIBGTOP_LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

UPOWER_CONFIGURE_ENABLE=upower
UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower

.include <bsd.port.mk>
