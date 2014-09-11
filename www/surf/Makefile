# Created by: Christopher Knaust <jigboe@gmx.de>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/
PKGNAMESUFFIX=	-browser

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web browser based on WebKit/Gtk+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

USE_GNOME=	gtk20
USE_XORG=	x11
USES=		pkgconfig

PORTDOCS=	README
PLIST_FILES=	bin/surf share/pixmaps/surf.png man/man1/surf.1.gz
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Surf" "" "${PREFIX}/share/pixmaps/surf.png" "surf" "" true

CONFLICTS=	surf-1* # math/surf

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
	@${REINPLACE_CMD} -e \
		'/^PREFIX/d ; \
		 s|/share/man|/man| ; \
		 /^X11INC =/s/=.*/= `pkg-config --cflags x11`/ ; \
		 /^X11LIB =/s/=.*/= `pkg-config --libs x11`/ ; \
		 /^CPPFLAGS =/s|$$| ${CPPFLAGS}| ; \
		 /^CFLAGS =/s|-Os| ${CFLAGS}| ; \
		 /^LDFLAGS =/s|$$| ${LDFLAGS}| ; \
		 /^CC =/d' ${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/surf
	(cd ${WRKSRC} && ${INSTALL_DATA} surf.png ${STAGEDIR}${PREFIX}/share/pixmaps)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
