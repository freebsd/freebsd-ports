# Created by: stolz@i2.informatik.rwth-aachen.de
# $FreeBSD$

PORTNAME=	fortune-mod-futurama
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Compilation of quotes from the TV series "Futurama"

USE_BZIP2=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	share/games/fortune/futurama share/games/fortune/futurama.dat
PLIST_DIRS=	share/games/fortune share/games

do-build:
	@cd ${WRKSRC} && /usr/games/strfile futurama

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/futurama* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
