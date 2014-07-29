# Created by: Thomas E. Zander
# $FreeBSD$

PORTNAME=	mplayer-fonts
PORTVERSION=	0.50
CATEGORIES=	multimedia
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~uedc/mplayer/ \
		http://www.rrr.de/~riggs/mplayer/

MAINTAINER=	riggs@rrr.de
COMMENT=	Font pack for the mplayer OSD and SUB

USES=	tar:bzip2
NO_BUILD=	yes

FONTDIRS=	cyrillic koi8r-font iso-8859-1/arial-14 \
		iso-8859-1/arial-18 iso-8859-1/arial-24 \
		iso-8859-1/arial-28 iso-8859-2/arial-14 \
		iso-8859-2/arial-18 iso-8859-2/arial-24 \
		iso-8859-2/arial-28

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mplayer/fonts
	@${CHMOD} 0555 ${STAGEDIR}${PREFIX}/share/mplayer/fonts
.for dir in iso-8859-1 iso-8859-2
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mplayer/fonts/${dir}
	@${CHMOD} 0555 ${STAGEDIR}${PREFIX}/share/mplayer/fonts/${dir}
.endfor
.for dir in ${FONTDIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mplayer/fonts/${dir}
	@${CHMOD} 0555 ${STAGEDIR}${PREFIX}/share/mplayer/fonts/${dir}
	@${INSTALL_DATA} ${WRKDIR}/${dir}/* \
		${STAGEDIR}${PREFIX}/share/mplayer/fonts/${dir}
.endfor

.include <bsd.port.mk>
