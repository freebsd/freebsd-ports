# New ports collection makefile for:	asbutton
# Date created:			10 May 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asbutton
PORTVERSION=	0.3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asbutton/

MAINTAINER=	jim@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	asbutton

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asbutton ${PREFIX}/bin
	@${ECHO} "===>   Installing icons in ${PREFIX}/share/asbutton"
	@${MKDIR} ${PREFIX}/share/asbutton && ${CHMOD} a+rx ${PREFIX}/share/asbutton
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${PREFIX}/share/asbutton

post-install:
	@${ECHO} "===>   Installing sample asbuttonrc in ${PREFIX}/share/examples/asbutton"
	@${ECHO} "===>   Copy to ~/.asbuttonrc and modify to desired config."
	@${MKDIR} ${PREFIX}/share/examples/asbutton && ${CHMOD} a+rx ${PREFIX}/share/examples/asbutton
	${INSTALL_DATA} ${WRKSRC}/.asbuttonrc ${PREFIX}/share/examples/asbutton/asbuttonrc && ${CHMOD} u+rw ${PREFIX}/share/examples/asbutton/asbuttonrc
	@${ECHO} "===>   Use 'asbutton -h' for help."

.include <bsd.port.mk>
