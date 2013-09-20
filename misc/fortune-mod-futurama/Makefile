# Created by: stolz@i2.informatik.rwth-aachen.de
# $FreeBSD$

PORTNAME=	fortune-mod-futurama
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compilation of quotes from the TV series "Futurama"

USE_BZIP2=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	share/games/fortune/futurama share/games/fortune/futurama.dat
PLIST_DIRS=	share/games/fortune share/games

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC} && /usr/games/strfile futurama

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/futurama* ${PREFIX}/share/games/fortune

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
