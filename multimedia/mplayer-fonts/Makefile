# New ports collection makefile for:	mplayer-fonts
# Date created:		15 August 2001
# Whom:			Thomas E. Zander
#
# $FreeBSD$
#

PORTNAME=	mplayer-fonts
PORTVERSION=	0.18
CATEGORIES=	graphics
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~uedc/mplayer/

MAINTAINER=	riggs@rrr.de

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/mplayer/fonts
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts
	@${MKDIR} ${PREFIX}/share/mplayer/fonts/iso
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts/iso
	@${MKDIR} ${PREFIX}/share/mplayer/fonts/cyrillic
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts/cyrillic
	@${MKDIR} ${PREFIX}/share/mplayer/fonts/koi8r
	@${CHMOD} 0555 ${PREFIX}/share/mplayer/fonts/koi8r
	@${INSTALL_DATA} ${WRKDIR}/iso/* ${PREFIX}/share/mplayer/fonts/iso
	@${INSTALL_DATA} ${WRKDIR}/cyrillic/* ${PREFIX}/share/mplayer/fonts/cyrillic
	@${INSTALL_DATA} ${WRKDIR}/koi8r/* ${PREFIX}/share/mplayer/fonts/koi8r/

.include <bsd.port.mk>
