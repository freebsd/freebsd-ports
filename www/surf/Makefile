# Created by: Christopher Knaust <jigboe@gmx.de>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	0.6
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web browser based on WebKit/Gtk+

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

USE_CSTD=	c99
USE_GNOME=	gtk20
USES=		pkgconfig

MAN1=		surf.1
PORTDOCS=	README
PLIST_FILES=	bin/surf share/pixmaps/surf.png

DESKTOP_ENTRIES="Surf" "" "${PREFIX}/share/pixmaps/surf.png" "surf" "" true

CONFLICTS=	surf-1* # math/surf

# Name conflicts with the math/surf port
NO_LATEST_LINK=	yes

NO_STAGE=	yes
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
		's|^\(PREFIX\)|#\1| ; \
		 s|/share/man|/man| ; \
		 s|^\(CFLAGS\) =.*|\1 += -I. $${GTKINC} $${CPPFLAGS}| ; \
		 s|^\(LDFLAGS\) =.*|\1 += $${GTKLIB}| ; \
		 s|^\(CC\)|#\1|' ${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/surf
	(cd ${WRKSRC} && ${INSTALL_DATA} surf.png ${PREFIX}/share/pixmaps)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR})
.endif

.include <bsd.port.mk>
