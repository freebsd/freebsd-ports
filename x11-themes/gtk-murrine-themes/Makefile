# New ports collection makefile for:	gtk-murrine-themes
# Date created:		2006-08-20
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-murrine-themes
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://cimi.netsons.org/media/download_gallery/
DISTNAME=	MurrineThemePack

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrine theme pack

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes
USE_BZIP2=	yes

do-install:
	@(for theme in MurrinaCandy MurrinaCappuccino MurrinaEalm MurrinaNeoGraphite; do \
		${MKDIR} ${LOCALBASE}/share/themes/$$theme/gtk-2.0; \
		${INSTALL_DATA} ${WRKDIR}/$$theme/gtk-2.0/gtkrc ${LOCALBASE}/share/themes/$$theme/gtk-2.0; \
	done);

.include <bsd.port.mk>
