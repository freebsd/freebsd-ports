# ex:ts=8
# New ports collection Makefile for:	rot
# Date created:			Sep 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rot
PORTVERSION=	1.2
CATEGORIES=	textproc
MASTER_SITES=	ftp://custom.lab.unb.br/pub/unix-c/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rotates a file so that lines become columns and vice versa

ALL_TARGET=	${PORTNAME}

MAN1=		rot.1
PLIST_FILES=	bin/rot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rot.man ${MAN1PREFIX}/man/man1/rot.1

.include <bsd.port.mk>
