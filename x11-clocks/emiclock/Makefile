# New ports collection makefile for:	EmiClock
# Date created:		15 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $FreeBSD$
#

PORTNAME=	emiclock
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://download.vector.co.jp/pack/unix/personal/tokei/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hyper-animated face analog clock for X11

USE_IMAKE=	yes
MAN1=		emiclock.1

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	${X11BASE}/lib/X11/ja_JP.eucJP/app-defaults
LANGDIR2=	${X11BASE}/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	${X11BASE}/lib/X11/EmiClock
PORTDOCS=	COPYRIGHT COPYRIGHT.en

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB=	SOUND="@comment "
.else
PLIST_SUB=	SOUND=""
.endif

pre-install:
	@${MKDIR} ${EMICLOCKDIR}
	@${MKDIR} ${LANGDIR}
	@${MKDIR} ${LANGDIR2}
	cd ${WRKSRC}; ${INSTALL_DATA} -c -m 0444 ${LANGRES} ${LANGDIR}/EmiClock
	cd ${WRKSRC}; ${INSTALL_DATA} -c -m 0444 ${LANGRES} ${LANGDIR2}/EmiClock
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} -c -m 0444 ${PORTDOCS} ${DOCSDIR}
#	cd ${WRKSRC}; make install.man

.include <bsd.port.post.mk>
