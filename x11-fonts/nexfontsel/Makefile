# New ports collection makefile for:	nexfontsel
# Date created:		99/09/29
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexfontsel
PORTVERSION= 	3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/
DISTNAME=	NeXFontSel-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} >= 4
LIB_DEPENDS=	neXtaw.7:${PORTSDIR}/x11-toolkits/neXtaw
.else
LIB_DEPENDS=	neXtaw.6:${PORTSDIR}/x11-toolkits/neXtaw
.endif

USE_IMAKE=	yes
MAN1=		nexfontsel.1

post-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
	${INSTALL_DATA} ${WRKSRC}/NeXFontSel-ja.ad ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/NeXFontSel

.include <bsd.port.post.mk>
