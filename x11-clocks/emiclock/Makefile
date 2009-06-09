# New ports collection makefile for:	EmiClock
# Date created:		15 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $FreeBSD$
#

PORTNAME=	emiclock
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://download.vector.co.jp/pack/unix/personal/tokei/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hyper-animated face analog clock for X11

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		emiclock.1

LANGRES=	resources/R6/EUC/EmiClock.ad
LANGDIR=	${LOCALBASE}/lib/X11/ja_JP.eucJP/app-defaults
LANGDIR2=	${LOCALBASE}/lib/X11/ja_JP.EUC/app-defaults
EMICLOCKDIR=	${LOCALBASE}/lib/X11/EmiClock

.ifndef NOPORTDOCS
PORTDOCS=	COPYRIGHT COPYRIGHT.en
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB=	SOUND="@comment "
.else
PLIST_SUB=	SOUND=""
.endif

post-install:
	@${MKDIR} ${EMICLOCKDIR}
	@${MKDIR} ${LANGDIR}
	@${MKDIR} ${LANGDIR2}
	cd ${WRKSRC} && ${INSTALL_DATA} ${LANGRES} ${LANGDIR}/EmiClock
	cd ${WRKSRC} && ${INSTALL_DATA} ${LANGRES} ${LANGDIR2}/EmiClock
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
#	cd ${WRKSRC}; make install.man

.include <bsd.port.post.mk>
