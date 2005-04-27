# New ports collection makefile for:	gnome-art
# Date created:		2005-04-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-art
PORTVERSION=	0.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.miketech.net/gnome-art/download/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Frontend for art.gnome.org

RUN_DEPENDS=	gnome-splashscreen-manager:${PORTSDIR}/x11-themes/gnome-splashscreen-manager

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_RUBY=	yes
USE_REINPLACE=	yes
USE_RUBY_SETUP=	yes
GNOMEART_ICON=	${DATADIR}/glade/pixmaps/gnome-graphics.png

post-patch:
	@${SED} -e 's|%%COMMENT%%|${COMMENT}|; \
		s|%%GNOMEART_ICON%%|${GNOMEART_ICON}|' \
		< ${FILESDIR}/gnome-art.desktop.in \
		> ${WRKDIR}/gnome-art.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/gnome-art/ui/main_window.rb \
		${WRKSRC}/lib/gnome-art/ui/download_dialog.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/gnome-art.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
