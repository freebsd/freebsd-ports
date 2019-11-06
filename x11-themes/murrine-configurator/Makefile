# Created by: Ted Stodgell <tstodgell@gmail.com>
# $FreeBSD$

PORTNAME=	murrine-configurator
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/murrine/

MAINTAINER=	tstodgell@gmail.com
COMMENT=	GUI gtkrc configuration tool for the Murrine GTK engine

BROKEN=		unfetchable

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/lib/gtk-2.0/2.10.0/engines/libmurrine.so:x11-themes/gtk-murrine-engine \
		${LOCALBASE}/bin/zenity:x11/zenity

NO_BUILD=	yes
USES=	tar:bzip2
USE_GNOME=	gtk20

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/files/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/files/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/files/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
