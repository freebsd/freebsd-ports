# Created by: Nobuhiro Yasutomi
# $FreeBSD$

PORTNAME=	emiclock
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://ftp.vector.co.jp/pack/unix/personal/tokei/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hyper-animated face analog clock for X11

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	${LOCALBASE}/lib/X11/ja_JP.eucJP/app-defaults
LANGDIR2=	${LOCALBASE}/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	${LOCALBASE}/lib/X11/EmiClock

PORTDOCS=	COPYRIGHT COPYRIGHT.en

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB=	SOUND="@comment "
.else
PLIST_SUB=	SOUND=""
.endif

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${EMICLOCKDIR}
	@${MKDIR} ${STAGEDIR}${LANGDIR}
	@${MKDIR} ${STAGEDIR}${LANGDIR2}
	cd ${WRKSRC} && ${INSTALL_DATA} ${LANGRES} ${STAGEDIR}${LANGDIR}/EmiClock
	cd ${WRKSRC} && ${INSTALL_DATA} ${LANGRES} ${STAGEDIR}${LANGDIR2}/EmiClock
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
