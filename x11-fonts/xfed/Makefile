# New ports collection makefile for:    xfed
# Date created:         7 December 1994
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	xfed
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that will let you edit X fonts (.bdf files)

IGNOREFILES=	${DISTFILES}
USE_IMAKE=	yes
USE_XORG=	x11 xext
MAKE_FLAGS=	MANDIR=${PREFIX}/man/man1 BINDIR=${PREFIX}/bin -f
WRKSRC=		${WRKDIR}/xfed
MAN1=		xfed.1
PLIST_FILES=	bin/xfed

.include <bsd.port.mk>
