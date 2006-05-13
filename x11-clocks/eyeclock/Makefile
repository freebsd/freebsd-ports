# New ports collection makefile for:   EyeClock
# Date created:        4 September 1998
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	eyeclock
PORTVERSION=	2.0
CATEGORIES=	x11-clocks
MASTER_SITES=	http://download.vector.co.jp/pack/unix/personal/tokei/
DISTNAME=	eyeclk20
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clock with eyes following the mouse pointer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		eyeclock.1

post-patch:
	@${REINPLACE_CMD} -e "s#gcc#${CC}#" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eyeclock ${PREFIX}/bin/eyeclock
.for link in boyclock daemonclock girlclock henohenoclock margueriteclock \
	octopusclock punpunclock silicagelclock taroclock umeharaclock
	${LN} -sf eyeclock ${PREFIX}/bin/${link}
.endfor
	${INSTALL_MAN} ${WRKSRC}/eyeclock.man ${MANPREFIX}/man/man1/eyeclock.1
	${INSTALL_DATA} ${WRKSRC}/EyeClock.daemon \
		${PREFIX}/lib/X11/app-defaults/EyeClock
	@${MKDIR} ${PREFIX}/lib/X11/EyeClock
.for file in CHANGE COPYRIGHT EyeClock.daemon EyeClock.normal EyeClock.penguin \
	Makefile OMAKE.jpn README.jpn xpm/*.xpm
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/X11/EyeClock
.endfor

.include <bsd.port.mk>
