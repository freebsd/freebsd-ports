# Created by: Jonathan Liu <Net147@hotmail.com>
# $FreeBSD$

PORTNAME=	nitrogen
DISTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/l3ib/nitrogen/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Background browser and setter for X windows

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	gnome-icon-theme>0:misc/gnome-icon-theme \
		hicolor-icon-theme>0:misc/hicolor-icon-theme

USES=		compiler:c++11-lang gettext gmake gnome iconv localbase \
		pkgconfig xorg
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24
INSTALLS_ICONS=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-inotify

LIBS+=		-lX11

OPTIONS_DEFINE=		XINERAMA
OPTIONS_DEFAULT=	XINERAMA

XINERAMA_CONFIGURE_ENABLE=	xinerama
XINERAMA_USES=			xorg
XINERAMA_USE=			xorg=xinerama

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/data/icon-theme-installer
	@${REINPLACE_CMD} '/^LIBS =/s/$$/ @LIBS@/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
