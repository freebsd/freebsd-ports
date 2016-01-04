# Created by: Nobuhiro Yasutomi
# $FreeBSD$

PORTNAME=	emiclock
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	x11-clocks
MASTER_SITES=	LOCAL/nyan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hyper-animated face analog clock for X11

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
LANGDIR2=	${PREFIX}/lib/X11/ja_JP.EUC/app-defaults

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#if defined.*\(FreeBSDArchitecture\).*|#ifdef \1| ; \
		 /MakeDir/s|EmiClockLib|$$(DESTDIR)&| ; \
		 /INSTALL/s|EmiClockLib|$$(DESTDIR)&|' ${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e \
		'/USE_SOUND/s|#undef|#define|' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e \
		'/soundcard.h/s|machine|sys|' ${WRKSRC}/include/sound.h

post-install:
	@${MKDIR} ${STAGEDIR}${LANGDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${LANGRES} \
		${STAGEDIR}${LANGDIR}/EmiClock)
	@${MKDIR} ${STAGEDIR}${LANGDIR2}
	${LN} -sf ../../ja_JP.eucJP/app-defaults/EmiClock \
		${STAGEDIR}${LANGDIR2}/EmiClock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT COPYRIGHT.en \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
