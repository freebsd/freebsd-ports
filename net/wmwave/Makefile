# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmwave
DISTVERSION=	0-4
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	benjsc@FreeBSD.org
COMMENT=	Display 802.11 status in the WindowMaker Dock

USES=		xorg
USE_XORG=	xpm

PLIST_FILES=	bin/wmwave man/man1/wmwave.1.gz
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DWICACHE -I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib -lX11 -lXpm -lXext -lm

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/wmgeneral.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwave.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
