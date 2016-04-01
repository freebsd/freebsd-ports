# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freetuxtv
PORTVERSION=	0.6.6
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WebTV player based on GTK3+ and LibVLC

LICENSE=	GPLv3

LIB_DEPENDS=	libvlc.so:multimedia/vlc \
		libdbus-glib-1.so:devel/dbus-glib \
		libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl \
		libnotify.so:devel/libnotify

USES=		gmake iconv libtool pkgconfig
USE_GNOME=	gtk30 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0
CFLAGS+=	-Wno-return-type -w
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
NLS_BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

SUB_FILES=	pkg-message

pre-configure:
	${REINPLACE_CMD} -e 's|$${pkgdatadir}/doc|$${pkgdocdir}|' \
		-e 's|install-data-am: install-freetuxtvdocDATA|install-data-am: |' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/libvlc_media_new_path/libvlc_media_new_location/' \
		${WRKSRC}/lib/libvlc-gtk/gtk-libvlc-media-player.c
	${REINPLACE_CMD} -e 's|g_strcasecmp|g_ascii_strcasecmp|' \
		${WRKSRC}/src/main.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
