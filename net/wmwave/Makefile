PORTNAME=	wmwave
DISTVERSION=	0-4
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	benjsc@FreeBSD.org
COMMENT=	Display 802.11 status in the WindowMaker Dock
WWW=		https://sourceforge.net/projects/wmwave/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		localbase:ldflags xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/wmwave share/man/man1/wmwave.1.gz
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DWICACHE
LDFLAGS+=	-lX11 -lXpm -lXext -lm

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/wmgeneral.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwave.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
