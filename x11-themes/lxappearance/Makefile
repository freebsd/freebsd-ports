# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxappearance
PORTVERSION=	0.6.3
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Desktop-independent theme switcher for GTK+

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-tools gmake gnome localbase pathfix pkgconfig tar:xz \
		xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool
CONFIGURE_ARGS=	--enable-dbus

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
