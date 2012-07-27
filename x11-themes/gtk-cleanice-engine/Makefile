# New ports collection makefile for:	gtk-cleanice-engine
# Date Created:				13 March 2003
# Whom:					Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	gtk-cleanice-engine
PORTVERSION=	2.4.1
PORTREVISION=	5
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/elysium-project/gtk-engines-cleanice/${PORTVERSION} \
		SF/elysium-project/gtk-engines-cleanice/1.2.7:theme
DISTNAME=	gtk-engines-cleanice-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${THEME}${EXTRACT_SUFX}:theme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simplistic GTK+ 2.x theme engine

USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	build

THEME=		cleanice-theme-1.2.7
THEMEDIR=	${WRKDIR}/${THEME}/Theme

post-install:
	@${MKDIR} ${PREFIX}/share/themes/CleanIce
	${INSTALL_DATA} ${THEMEDIR}/cleanice/index.theme \
		${PREFIX}/share/themes/CleanIce
	@${MKDIR} ${PREFIX}/share/themes/CleanIce/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice/gtkrc \
		${PREFIX}/share/themes/CleanIce/gtk-2.0
	@${MKDIR} ${PREFIX}/share/themes/CleanIce/metacity-1
	${INSTALL_DATA} ${THEMEDIR}/cleanice/metacity-theme-1.xml \
		${PREFIX}/share/themes/CleanIce/metacity-1
	@${MKDIR} ${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice-dark/gtkrc \
		${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0

.include <bsd.port.mk>
