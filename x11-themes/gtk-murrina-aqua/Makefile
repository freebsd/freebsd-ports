# New ports collection makefile for:	gtk-murrina-aqua
# Date created:		2006-08-20
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-murrina-aqua
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www5.frugalware.org/packages/frugalware/pub/frugalware/frugalware-stable/source/gnome-extra/gtk+2-engines-murrine/
MASTER_SITE_SUBDIR=	itetcu
DISTNAME=	Murrina-Aqua

MAINTAINER=	pneumann@gmail.com
COMMENT=	Murrina Aqua GTK+ 2.x cairo based theme

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine
RUN_DEPENDS=	${LOCALBASE}/lib/gtk-2.0/${GTK2_VERSION}/engines/libmurrine.la:${PORTSDIR}/x11-themes/gtk-murrine-engine

GTKRC_DIR=	${DISTNAME}/gtk-2.0
USE_GNOME=	gtk20
NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/themes/${GTKRC_DIR}
	@${INSTALL_DATA} ${WRKDIR}/${GTKRC_DIR}/gtkrc ${LOCALBASE}/share/themes/${GTKRC_DIR}

.include <bsd.port.mk>
