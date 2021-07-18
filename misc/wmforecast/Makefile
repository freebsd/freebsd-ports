# Created by: Igor Pokrovsky <ip@unixway.org>

PORTNAME=	wmforecast
DISTVERSION=	1.6
CATEGORIES=	misc windowmaker geography
MASTER_SITES=	https://github.com/d-torrance/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ip@unixway.org
COMMENT=	Weather dockapp for Window Maker using the Yahoo Weather API

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgweather-3.so:net/libgweather \
		libWINGs.so:x11-wm/windowmaker \
		libwraster.so:x11-wm/libwraster

USES=		gmake gettext-runtime gnome pkgconfig xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
INSTALLS_ICONS=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	GEOCLUE NLS

GEOCLUE_DESC=	Use GeoClue

GEOCLUE_LIB_DEPENDS=	libgeoclue-2.so:net/geoclue
GEOCLUE_CONFIGURE_WITH=	geoclue
NLS_USES=	gettext

.include <bsd.port.mk>
