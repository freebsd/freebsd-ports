# New ports collection makefile for: CyrX-2
# Date created:		04 Janyary 1999
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	wmcyrx
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	russian windowmaker
MASTER_SITES=	http://ozz.pp.ru/distfiles/ \
		ftp://ftp.vistdon.ru/pub/unix/X/wmanagers/windowmaker/
DISTNAME=	cyrx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Cyrillic keyboard layout manager for Window Maker

USE_XORG=	x11 xpm
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/wmcyrx2
MAKE_ENV+=	COPT="${CXXFLAGS} -fpermissive"

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@ ${REINPLACE_CMD} 's|inline min|inline int min|' \
		${WRKSRC}/cyrx2.cc

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cyrx2 ${PREFIX}/bin/wmcyrx2

.include <bsd.port.mk>
