# Created by: David Leonard <leonard@dstc.edu.au>
# $FreeBSD$

PORTNAME=	dclock
PORTVERSION=	2.2.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://opencircuitdesign.com/~tim/programs/dclock/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 7-segment digital clock with some optional features

OPTIONS_DEFINE=	SOX XFT DOCS
OPTIONS_DEFAULT=SOX XFT
SOX_DESC=	Install SOX to play audio

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xt
USES=		pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXt -lm

PORTDOCS=	README TODO
PLIST_FILES=	bin/dclock \
		lib/X11/app-defaults/DClock \
		man/man1/${PORTNAME}.1.gz \
		%%DATADIR%%/sounds/bell.wav \
		%%DATADIR%%/sounds/digital.wav
PLIST_DIRS=	%%DATADIR%%/sounds \
		%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	play:${PORTSDIR}/audio/sox
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
CPPFLAGS+=	$$(freetype-config --cflags) -DXFT_SUPPORT
LDFLAGS+=	$$(freetype-config --libs) -lXft
.endif

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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
