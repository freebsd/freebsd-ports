# New ports collection makefile for:   fortune-mod-futurama
# Date created:        18 November 2002
# Whom:                stolz@i2.informatik.rwth-aachen.de
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-futurama
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	http://www.netmeister.org/apps/

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de

NO_BUILD=	yes

USE_BZIP2=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/games
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/futurama* ${PREFIX}/share/games/fortune

post-install:
	@${SED} 's#PREFIX#${PREFIX}#' <pkg-message

.include <bsd.port.mk>
