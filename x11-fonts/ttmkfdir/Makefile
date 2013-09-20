# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttmkfdir
PORTVERSION=	3.0.9
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-fonts x11
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create fonts.scale file for use with TrueType font server

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

PLIST_FILES=	bin/ttmkfdir
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include <bsd.port.mk>
