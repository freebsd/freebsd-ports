# New ports collection makefile for:	nexfontsel
# Version required:	2.0
# Date created:		99/09/29
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	NeXFontSel-2.0
PKGNAME=	nexfontsel-2.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/

MAINTAINER=	taoka@FreeBSD.org

LIB_DEPENDS=	neXtaw.6:${PORTSDIR}/x11-toolkits/neXtaw

USE_IMAKE=	yes
MAN1=		nexfontsel.1

post-install:
	${MKDIR} ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults
	${INSTALL_DATA} ${WRKSRC}/NeXFontSel-ja.ad ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults/NeXFontSel

.include <bsd.port.mk>
