# Created by: Christopher Knaust <jigboe@gmx.de>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	0.7
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/
PKGNAMESUFFIX=	-browser

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web browser based on WebKit/Gtk+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2
RUN_DEPENDS=	dmenu:x11/dmenu

USE_GNOME=	gtk20
USE_XORG=	x11
USES=		pkgconfig

PORTDOCS=	FAQ.md README TODO.md
PORTEXAMPLES=	surf-open.sh
PLIST_FILES=	bin/surf man/man1/surf.1.gz share/pixmaps/surf.png

DESKTOP_ENTRIES="Surf" "" "${PREFIX}/share/pixmaps/surf.png" "surf" "" true

CONFLICTS=	surf-1* # math/surf

OPTIONS_DEFINE=	BUILTIN_DOWNLOAD DOCS EXAMPLES
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

# http://surf.suckless.org/patches/download
# http://surf.suckless.org/patches/smoothscrolling-via-GTK3
BUILTIN_DOWNLOAD_DESC=	Built-in download support
BUILTIN_DOWNLOAD_CFLAGS=	-DBUILTIN_DOWNLOAD
GTK2_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2
GTK2_USE=		gnome=gtk20
GTK2_MAKE_ENV=		GTKINC="$$(pkg-config --cflags webkit-1.0)" \
			GTKLIB="$$(pkg-config --libs webkit-1.0)"
GTK3_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
GTK3_USE=		gnome=gtk30
GTK3_MAKE_ENV=		GTKINC="$$(pkg-config --cflags webkitgtk-3.0)" \
			GTKLIB="$$(pkg-config --libs webkitgtk-3.0)"
TOOLKIT_DESC=		Gtk+ toolkit

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG} "You can build surf with your own config.h using the SURF_CONF knob:"
	@${ECHO_MSG} "make SURF_CONF=/path/to/surf/config.h install clean"

post-extract:
.if defined(SURF_CONF)
	@${ECHO_MSG} "creating config.h from ${SURF_CONF}"
	@${CP} ${SURF_CONF} ${WRKSRC}/config.h
.endif

post-patch:
	${REINPLACE_CMD} -e \
		'/^PREFIX/s| =| ?=| ; \
		/^MANPREFIX/s|/share/man|/man| ; \
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/surf
	(cd ${WRKSRC} && ${INSTALL_DATA} surf.png \
		${STAGEDIR}${PREFIX}/share/pixmaps)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
