# Created by: David Leonard <leonard@dstc.edu.au>
# $FreeBSD$

PORTNAME=	dclock
PORTVERSION=	2.2.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://opencircuitdesign.com/~tim/programs/dclock/archive/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	7-segment digital clock with some optional features

USES=		pkgconfig tar:tgz xorg
USE_XORG=	x11 xt

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXt -lm

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README TODO
PLIST_FILES=	bin/dclock \
		lib/X11/app-defaults/DClock \
		man/man1/${PORTNAME}.1.gz \
		%%DATADIR%%/sounds/bell.wav \
		%%DATADIR%%/sounds/digital.wav

OPTIONS_DEFINE=	SOX XFT DOCS
OPTIONS_DEFAULT=SOX XFT
SOX_DESC=	Install SOX to play audio
SOX_RUN_DEPENDS=	play:audio/sox

XFT_USE=	XORG=xft
XFT_CPPFLAGS=	$$(freetype-config --cflags) -DXFT_SUPPORT
XFT_LDFLAGS=	$$(freetype-config --libs) -lXft

post-patch:
.for i in Dclock.c Dclock.ad dclock.1
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${i}
.endfor

do-build:
	(cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} ${CPPFLAGS} *.c -o ${PORTNAME} ${LDFLAGS})

do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} dclock ${STAGEDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} dclock.1 ${STAGEDIR}${MANPREFIX}/man/man1 \
		&& ${INSTALL_DATA} Dclock.ad \
			${STAGEDIR}${PREFIX}/lib/X11/app-defaults/DClock)
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	(cd ${WRKSRC}/sounds && ${INSTALL_DATA} *.wav ${STAGEDIR}${DATADIR}/sounds)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
