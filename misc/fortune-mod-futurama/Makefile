# New ports collection makefile for:   fortune-mod-futurama
# Date created:        18 November 2002
# Whom:                stolz@i2.informatik.rwth-aachen.de
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-futurama
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/

MAINTAINER=	vs@FreeBSD.org
COMMENT=	Compilation of quotes from the TV series "Futurama"

USE_BZIP2=	yes

PLIST_FILES=	share/games/fortune/futurama share/games/fortune/futurama.dat
PLIST_DIRS=	share/games/fortune share/games

do-build:
	@cd ${WRKSRC} && strfile futurama

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/futurama* ${PREFIX}/share/games/fortune

post-install:
	@${SED} 's#PREFIX#${PREFIX}#' <pkg-message

.include <bsd.port.mk>
