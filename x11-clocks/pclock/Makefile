# New ports collection makefile for:	pclock
# Date created:			15 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pclock
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker afterstep
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple analog clock program for the Window Maker dock

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GETOPT_LONG=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" OBJS="Main.o Graphics.o" \
		INCDIR="-I. -I${X11BASE}/include ${CPPFLAGS}" \
		LIBDIR="-L${X11BASE}/lib ${LDFLAGS}"

post-extract:
	cd ${WRKSRC} && ${RM} -f getopt*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pclock ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../XPM/*.xpm ${DATADIR}/pixmaps

.include <bsd.port.mk>
