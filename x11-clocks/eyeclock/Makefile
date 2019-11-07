# Created by: KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	eyeclock
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	x11-clocks
MASTER_SITES=	http://ftp.vector.co.jp/12/89/1347/
DISTNAME=	eyeclk20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clock with eyes following the mouse pointer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ENV=	X11BASE=${LOCALBASE}
USES=		tar:tgz xorg
USE_XORG=	x11 xau xdmcp xpm xt ice

DESKTOP_ENTRIES="EyeClock" "" "" "eyeclock" "" ""

post-patch:
	@${REINPLACE_CMD} -e "s#gcc#${CC}#" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eyeclock ${STAGEDIR}${PREFIX}/bin/eyeclock
.for link in boyclock daemonclock girlclock henohenoclock margueriteclock \
	octopusclock punpunclock silicagelclock taroclock umeharaclock
	${LN} -sf eyeclock ${STAGEDIR}${PREFIX}/bin/${link}
.endfor
	${INSTALL_MAN} ${WRKSRC}/eyeclock.man ${STAGEDIR}${MANPREFIX}/man/man1/eyeclock.1
	${INSTALL_DATA} ${WRKSRC}/EyeClock.daemon \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/EyeClock
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/EyeClock
.for file in CHANGE COPYRIGHT EyeClock.daemon EyeClock.normal EyeClock.penguin \
	Makefile OMAKE.jpn README.jpn xpm/*.xpm
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/lib/X11/EyeClock
.endfor

.include <bsd.port.mk>
