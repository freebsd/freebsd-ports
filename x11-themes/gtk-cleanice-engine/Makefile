# New ports collection makefile for:	gtk-cleanice-engine
# Date Created:				13 March 2003
# Whom:					Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	gtk-cleanice-engine
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	elysium-project
DISTNAME=	gtk-engines-cleanice-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		${THEME}.tar.gz

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A simplistic GTK+ 2.x theme engine

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack gtk20

THEME=		cleanice-theme-1.2.7
THEMEDIR=	${WRKDIR}/${THEME}/Theme

post-install:
	${MKDIR} ${PREFIX}/share/themes/CleanIce/gtk-2.0
	${MKDIR} ${PREFIX}/share/themes/CleanIce/metacity-1
	${MKDIR} ${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice/index.theme \
		${PREFIX}/share/themes/CleanIce
	${INSTALL_DATA} ${THEMEDIR}/cleanice/gtkrc \
		${PREFIX}/share/themes/CleanIce/gtk-2.0
	${INSTALL_DATA} ${THEMEDIR}/cleanice/metacity-theme-1.xml \
		${PREFIX}/share/themes/CleanIce/metacity-1
	${INSTALL_DATA} ${THEMEDIR}/cleanice-dark/gtkrc \
		${PREFIX}/share/themes/CleanIce-Dark/gtk-2.0

.include <bsd.port.mk>
