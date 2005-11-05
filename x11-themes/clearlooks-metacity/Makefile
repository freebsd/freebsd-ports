# New ports collection makefile for:	clearlooks-metacity
# Date created:		2005-03-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/clearlooks-metacity/Makefile,v 1.1 2005/08/08 15:27:13 kwm Exp $
#

PORTNAME=	clearlooks-metacity
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clearlooks

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Clearlooks Metacity theme

CONFLICTS=	gnome-themes-2.11.9[1-9]* gnome-themes-2.12.*

WRKSRC=		${WRKDIR}/Clearlooks/metacity-1/
USE_GNOME=	metacity gnomeprefix
USE_X_PREFIX=	yes
DATADIR=	share/gnome/themes/Clearlooks/metacity-1
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/metacity-theme-1.xml
PLIST_DIRS=	%%DATADIR%% \
		share/gnome/themes/Clearlooks

do-install:
	${MKDIR} ${PREFIX}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metacity-theme-1.xml ${PREFIX}/${DATADIR}

.include <bsd.port.mk>
