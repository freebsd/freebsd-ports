PORTNAME=	surf
DISTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/
PKGNAMESUFFIX=	-browser

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web browser based on WebKit2/GTK
WWW=		https://surf.suckless.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
		libsoup-2.4.so:devel/libsoup \
		libgcr-base-3.so:security/gcr3
RUN_DEPENDS=	dmenu:x11/dmenu \
		curl:ftp/curl \
		xterm:x11/xterm

USES=		compiler:c11 cpe gnome pkgconfig xorg
USE_GNOME=	gtk30 pango cairo gdkpixbuf
USE_XORG=	x11

CPE_VENDOR=	suckless

CONFLICTS=	surf-1* # math/surf

DESKTOP_ENTRIES="Surf" "" "${PREFIX}/share/pixmaps/surf.png" "surf" "" true

PLIST_FILES=	bin/surf \
		lib/surf/webext-surf.so \
		share/man/man1/surf.1.gz \
		share/pixmaps/surf.png

PORTDOCS=	README TODO.md
PORTEXAMPLES=	surf-open.sh

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-everything::
	@${ECHO_MSG} "You can build surf with your own config.h using the SURF_CONF knob:"
	@${ECHO_MSG} "make SURF_CONF=/path/to/surf/config.h install clean"
	@${ECHO_MSG} "Note: Pre-${PORTVERSION} config.h-files may not work."

post-extract:
.if defined(SURF_CONF)
	@${ECHO_MSG} "creating config.h from ${SURF_CONF}"
	@${LN} -sf ${SURF_CONF} ${WRKSRC}/config.h
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s| =| ?=| ; \
		/^X11/s|/usr/X11R6/|$${LOCALBASE}/| ; \
		/^GTKINC/s| =| ?=| ; \
		/^GTKLIB/s| =| ?=| ; \
		/^INCS/s|-I/usr/include || ; \
		/^LIBS/s|-L/usr/lib -lc || ; \
		/^CPPFLAGS/s| =| +=| ; \
		/^CFLAGS/s| =| +=| ; \
		/^CFLAGS/s|-Os || ; \
		/^LDFLAGS/s| =| +=| ; \
		/^LDFLAGS/s|-g || ; \
		/^CC/s| =| ?=|' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|st -e|xterm -e|' ${WRKSRC}/config.def.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/surf
	${INSTALL_DATA} ${WRKSRC}/surf.png ${STAGEDIR}${PREFIX}/share/pixmaps

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
