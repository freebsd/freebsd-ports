# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freetuxtv
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WebTV player based on GTK3+ and LibVLC

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable (google code has gone away)

LIB_DEPENDS=	libvlc.so:multimedia/vlc \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libcurl.so:ftp/curl \
		libnotify.so:devel/libnotify

USES=		gmake iconv libtool localbase pkgconfig sqlite
USE_GNOME=	cairo gtk30 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0
CFLAGS+=	-Wno-return-type -w
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
	(cd ${STAGEDIR}${PREFIX}/share/pixmaps && \
		${LN} -sf ../icons/hicolor/48x48/apps/${PORTNAME}.png)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
