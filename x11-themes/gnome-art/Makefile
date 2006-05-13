# New ports collection makefile for:	gnome-art
# Date created:		2005-04-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-art
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.miketech.net/gnome-art/download/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Frontend for art.gnome.org

RUN_DEPENDS=	gnome-splashscreen-manager:${PORTSDIR}/x11-themes/gnome-splashscreen-manager

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
GNOMEART_ICON=	${DATADIR}/glade/pixmaps/gnome-graphics.png
DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "${GNOMEART_ICON}" "${PORTNAME}" "Application;Settings;AdvancedSettings;" true

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/lib/gnome-art/ui/main_window.rb \
		${WRKSRC}/lib/gnome-art/ui/download_dialog.rb
	@${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.mk>
