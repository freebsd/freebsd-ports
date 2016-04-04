# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	nitrogen
PORTVERSION=	1.5.2
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://projects.l3ib.org/nitrogen/files/

MAINTAINER=	corentin@ralite.com
COMMENT=	Background browser and setter for X windows

LICENSE=	GPLv2+

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	gnome-icon-theme>0:misc/gnome-icon-theme \
		hicolor-icon-theme>0:misc/hicolor-icon-theme

OPTIONS_DEFINE=	XINERAMA
OPTIONS_DEFAULT=XINERAMA

USES=		gettext iconv pkgconfig
USE_GNOME=	gtkmm24
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-inotify
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

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
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ @LIBS@/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
