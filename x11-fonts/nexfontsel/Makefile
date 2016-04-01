# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nexfontsel
PORTVERSION=	3.0.1
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/ \
		LOCAL/pav
DISTNAME=	NeXFontSel-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NeXtaw based replacement for xfontsel

LIB_DEPENDS=	libneXtaw.so:x11-toolkits/neXtaw

USES=		imake
USE_XORG=	xaw

post-patch:
	@${REINPLACE_CMD} -e 's|^CDEBUG|XCOMM CDEBUG|g ; \
		s|= XawClientLibs|= -lneXtaw -lXmu -lXt -lX11|g' ${WRKSRC}/Imakefile

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/NeXFontSel-ja.ad \
		${STAGEDIR}${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/NeXFontSel

.include <bsd.port.mk>
