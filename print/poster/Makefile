# New ports collection makefile for:	poster
# Date created:		15 January 2000
# Whom:			Yoshiro MIHIRA <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	poster
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ics.ele.tue.nl/pub/users/jos/poster/
DISTNAME=	poster

MAINTAINER=	sanpei@FreeBSD.org

ALL_TARGET=	poster
NO_WRKSUBDIR=	yes

MAN1=		poster.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
