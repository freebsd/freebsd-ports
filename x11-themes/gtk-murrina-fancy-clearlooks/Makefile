# New ports collection makefile for:	gtk-murrina-fancy-clearlooks
# Date created:		2006-12-07
# Whom:			pneumann@gmail.com
#
# $FreeBSD$
#

PORTNAME=	gtk-murrina-fancy-clearlooks
PORTVERSION=	0.3
CATEGORIES=	x11-themes
MASTER_SITES=	http://home.planet.nl/~bassa052/
DISTNAME=	MurrinaFancyClearlooks_v0.3

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine fancy clearlooks themes pack

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine

WRKSRC=	${WRKDIR}/MurrinaFancyClearlooks/
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC} && for theme in *; do \
		${MKDIR} ${LOCALBASE}/share/themes/$$theme/gtk-2.0; \
		${INSTALL_DATA} ${WRKSRC}/$$theme/gtk-2.0/gtkrc ${LOCALBASE}/share/themes/$$theme/gtk-2.0; \
		${INSTALL_DATA} ${WRKSRC}/$$theme/gtk-2.0/panel_bg.png ${LOCALBASE}/share/themes/$$theme/gtk-2.0; \
	done);

.include <bsd.port.mk>
