# ex:ts=8
# New ports collection makefile for:	gman
# Date created:			Mar 30, 3001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gman
PORTVERSION=	0.9.2
CATEGORIES=	misc
MASTER_SITES=	http://homex.coolconnect.com/user/xkwang/gman/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	ghostview:${PORTSDIR}/print/ghostview

USE_GTK=	yes

MAN1=	gman.1x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gman ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gman.1x ${MANPREFIX}/man/man1

.include <bsd.port.mk>
