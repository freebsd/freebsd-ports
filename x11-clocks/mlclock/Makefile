# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	mlclock
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clock for mlvwm window manager

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		xorg
USE_XORG=	x11 xau xdmcp

PLIST_FILES=	bin/mlclock %%DATADIR%%/mlclockrc %%DATADIR%%/mlclockrc-kanji

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void main|int main| ; \
		 s|log|logical|' ${WRKSRC}/mlclock.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include \
		-DRCFILE=\".mlclockrc\" mlclock.c -o mlclock \
		-L${LOCALBASE}/lib -lX11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mlclock ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in mlclockrc mlclockrc-kanji
	${INSTALL_DATA} ${WRKSRC}/rcfile/${i} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
