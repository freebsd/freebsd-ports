# Created by: Albert Graef <ag@muwiinfa.geschichte.uni-mainz.de>
# $FreeBSD$

PORTNAME=	xplore
PORTVERSION=	1.2a
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Motif file manager

LICENSE=	GPLv2

USES=		imake
USE_GCC=	any
USE_MOTIF=	yes
USE_XORG=	xpm
MAKE_JOBS_UNSAFE=yes
CFLAGS+=	-Wno-return-type

MAN1=		xplore.1 xploretype.1

post-patch:
	@${REINPLACE_CMD} -e 's| read| read dummy|g' ${WRKSRC}/system.xplorerc

.include <bsd.port.mk>
