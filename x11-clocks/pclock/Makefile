# New ports collection makefile for:	pclock
# Date created:			15 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pclock
PORTVERSION=	0.13.1
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	ftp://ftp.kourakos.com/pub/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jim@FreeBSD.org

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/pclock ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pclock/pixmaps && ${CHMOD} a+rx ${PREFIX}/share/pclock/pixmaps
	@${ECHO} "===>  Installing sample pixmaps in ${PREFIX}/share/pclock/pixmaps"
	@${INSTALL_DATA} ${WRKSRC}/XPM/*.xpm ${PREFIX}/share/pclock/pixmaps

post-install:
	@${ECHO} "===>  Use 'pclock --help' for usage instructions"

.include <bsd.port.mk>
