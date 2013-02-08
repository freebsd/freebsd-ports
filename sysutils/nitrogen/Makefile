# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	nitrogen
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.l3ib.org/nitrogen/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background browser and setter for X windows

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	atkmm:${PORTSDIR}/accessibility/atkmm \
		glibmm:${PORTSDIR}/devel/glibmm \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		cairomm:${PORTSDIR}/graphics/cairomm \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pangomm:${PORTSDIR}/x11-toolkits/pangomm \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	gnome-icon-theme>0:${PORTSDIR}/misc/gnome-icon-theme \
		hicolor-icon-theme>0:${PORTSDIR}/misc/hicolor-icon-theme

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=XINERAMA

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GNOME=	gtk20
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-inotify
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		nitrogen.1

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
