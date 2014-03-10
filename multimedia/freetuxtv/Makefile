# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	freetuxtv
PORTVERSION=	0.6.5
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	WebTV player based on GTK2+ and LibVLC

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libvlc.so:${PORTSDIR}/multimedia/vlc \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		gmake iconv pathfix pkgconfig
USE_GNOME=	gtk20 cairo
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk=2.0
CFLAGS+=	-Wno-return-type -w
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

SUB_FILES=	pkg-message

# Wrong versioning upstream, Upstream use GTK3 in newer Versions
PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|$${pkgdatadir}/doc|$${PREFIX}/share/doc/${PORTNAME}|' \
		-e 's|install-data-am: install-freetuxtvdocDATA|install-data-am: |' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/libvlc_media_new_path/libvlc_media_new_location/' \
		${WRKSRC}/lib/libvlc-gtk/gtk-libvlc-media-player.c
	@${REINPLACE_CMD} -e 's|g_strcasecmp|g_ascii_strcasecmp|' \
		${WRKSRC}/src/main.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
