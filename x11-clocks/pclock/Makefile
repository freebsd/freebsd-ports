# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pclock
PORTVERSION=	0.13.1
PORTREVISION=	4
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple analog clock program for the Window Maker dock

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig/src

USE_XORG=	x11 xau xdmcp xext xpm
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" OBJS="Main.o Graphics.o" \
		INCDIR="-I. -I${LOCALBASE}/include ${CPPFLAGS}" \
		LIBDIR="-L${LOCALBASE}/lib ${LDFLAGS}"

post-extract:
	cd ${WRKSRC} && ${RM} getopt*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pclock ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../XPM/*.xpm ${STAGEDIR}${DATADIR}/pixmaps

.include <bsd.port.mk>
