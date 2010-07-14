# New ports collection makefile for:   surf
# Date created:                December 21, 2009
# Whom:                        Christopher Knaust <jigboe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	surf
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/

MAINTAINER=	jigboe@gmx.de
COMMENT=	A simple Web browser based on WebKit/Gtk+

LIB_DEPENDS=	webkit-1.0:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

USE_GNOME=	gtk20 pkgconfig

MAN1=		surf.1
PLIST_FILES=	bin/surf
PORTDOCS=	LICENSE README

# Name conflicts with the math/surf port
NO_LATEST_LINK=	yes

pre-everything::
	@${ECHO_MSG} "You can build surf with your own config.h using the SURF_CONF knob:"
	@${ECHO_MSG} "make SURF_CONF=/path/to/surf/config.h install clean"

post-extract:
.if defined(SURF_CONF)
	@${ECHO_MSG} "creating config.h from ${SURF_CONF}"
	@${CP} ${SURF_CONF} ${WRKSRC}/config.h
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
