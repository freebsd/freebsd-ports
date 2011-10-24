# New ports collection makefile for:	ttmkfdir
# Date created:		September 08, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttmkfdir
PORTVERSION=	3.0.9
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-fonts x11
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create fonts.scale file for use with TrueType font server

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

PLIST_FILES=	bin/ttmkfdir
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include <bsd.port.mk>
