# New ports collection makefile for:	nexfontsel
# Date created:		99/09/29
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexfontsel
PORTVERSION=	3.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	NeXFontSel-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neXtaw based replacement for xfontsel

LIB_DEPENDS=	neXtaw:${PORTSDIR}/x11-toolkits/neXtaw

USE_IMAKE=	yes
USE_REINPLACE=	yes

MAN1=		nexfontsel.1

post-patch:
	@${REINPLACE_CMD} -e 's|^CDEBUG|XCOMM CDEBUG|g' ${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/NeXFontSel-ja.ad \
		${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/NeXFontSel

.include <bsd.port.mk>
