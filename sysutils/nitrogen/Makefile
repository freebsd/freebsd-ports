# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	nitrogen
PORTVERSION=	1.5.2
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.l3ib.org/nitrogen/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background browser and setter for X windows

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libatkmm-1.6.so:${PORTSDIR}/accessibility/atkmm \
		libglibmm-2.4.so:${PORTSDIR}/devel/glibmm \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libcairomm-1.0.so:${PORTSDIR}/graphics/cairomm \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libpangomm-1.4.so:${PORTSDIR}/x11-toolkits/pangomm
RUN_DEPENDS=	gnome-icon-theme>0:${PORTSDIR}/misc/gnome-icon-theme \
		hicolor-icon-theme>0:${PORTSDIR}/misc/hicolor-icon-theme

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=XINERAMA

USES=		gettext iconv pkgconfig
USE_GNOME=	gtk20
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-inotify
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Nitrogen" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
		"Graphics;Viewer;" true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
CONFIGURE_ARGS+=--enable-xinerama
.else
CONFIGURE_ARGS+=--disable-xinerama
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/data/icon-theme-installer

.include <bsd.port.mk>
