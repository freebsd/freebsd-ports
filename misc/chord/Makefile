# New ports collection makefile for:	chord
# Date created:		24 April 1995
# Whom:			Satoshi Asami
#
# $FreeBSD$
#

PORTNAME=	chord
PORTVERSION=	3.6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce PS sheet-music from text input

CFLAGS+=	-DPAPERSIZE=US
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/chord bin/a2crd
MAN1=		a2crd.1 chord.1

do-install:
.	for m in ${MAN1:R}
	@${INSTALL_MAN} ${WRKSRC}/${m}.man ${MANPREFIX}/man/man1/${m}.1
.	endfor
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PLIST_FILES:T} ${PREFIX}/bin

.include <bsd.port.mk>
