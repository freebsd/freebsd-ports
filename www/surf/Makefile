# Created by: Christopher Knaust <jigboe@gmx.de>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web browser based on WebKit/Gtk+

LIB_DEPENDS=	webkitgtk-1:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

USE_GNOME=	gtk20
USE_PKGCONFIG=	yes

MAN1=		surf.1
PLIST_FILES=	bin/surf
PORTDOCS=	LICENSE README

CONFLICTS=	surf-1* # math/surf

# Name conflicts with the math/surf port
NO_LATEST_LINK=	yes

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG} "You can build surf with your own config.h using the SURF_CONF knob:"
	@${ECHO_MSG} "make SURF_CONF=/path/to/surf/config.h install clean"

post-extract:
.if defined(SURF_CONF)
	@${ECHO_MSG} "creating config.h from ${SURF_CONF}"
	@${CP} ${SURF_CONF} ${WRKSRC}/config.h
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
