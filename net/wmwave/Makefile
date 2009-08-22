# New ports collection makefile for:	wmwave
# Date created:		27 December 2001
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmwave
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	benjsc@FreeBSD.org
COMMENT=	Display 802.11 status in the WindowMaker Dock

USE_XORG=	xpm

MAN1=		wmwave.1
PLIST_FILES=	bin/wmwave

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-DWICACHE -I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib -lX11 -lXpm -lXext -lm

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/wmgeneral.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
