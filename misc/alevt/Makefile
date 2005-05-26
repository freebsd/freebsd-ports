# New ports collection makefile for:	AleVT
# Date created:				Wed Aug 18 13:23:00 BST 1999
# Whom:					Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	alevt
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.goron.de/~froese/alevt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 teletext decoding and display program

OPTIONS=	PNG		"Export pages as PNG image"	on \
		SMALLFONT	"Use a smaller and thiner font"	off

USE_X_PREFIX=	yes
MAN1=		alevt.1x alevt-date.1 alevt-cap.1

.include <bsd.port.pre.mk>

.if defined(WITH_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
MAKE_ARGS+=	-DWITH_PNG
.endif

.if defined(WITH_SMALLFONT)
MAKE_ARGS+=	-DWITH_SMALLFONT
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alevt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/alevt-date ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/alevt-cap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/alevt.1x ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/alevt-date.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/alevt-cap.1 ${PREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/mini-alevt.xpm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/icon-old.xbm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/icon48x48.xpm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/icon54x60.xpm ${DATADIR}

.include <bsd.port.post.mk>
