# New ports collection makefile for:	clearlooks-metacity
# Date created:		2005-03-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clearlooks-metacity
PORTVERSION=	0.5.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/content/files/
DISTNAME=	21237-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Clearlooks Metacity theme

WRKSRC=		${WRKDIR}/Clearlooks
USE_GNOME=	metacity gnomeprefix
USE_X_PREFIX=	yes
DATADIR=	share/gnome/themes/Clearlooks/metacity-1
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/metacity-theme-1.xml
PLIST_DIRS=	%%DATADIR%% \
		share/gnome/themes/Clearlooks

do-install:
	${MKDIR} ${PREFIX}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/metacity-1/metacity-theme-1.xml ${PREFIX}/${DATADIR}

.include <bsd.port.mk>
