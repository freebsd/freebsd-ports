# New ports collection makefile for:    xfed
# Date created:         7 December 1994
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	xfed
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://ftp.yars.free.net/pub/software/unix/X11/fonts/edit/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that will let you edit X fonts (.bdf files)

IGNOREFILES=	${DISTFILES}
USE_IMAKE=	yes
MAKE_FLAGS=	MANDIR=${PREFIX}/man/man1 BINDIR=${PREFIX}/bin -f
WRKSRC=		${WRKDIR}/xfed
MAN1=		xfed.1
PLIST_FILES=	bin/xfed

.include <bsd.port.mk>
