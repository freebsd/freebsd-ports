# New ports collection makefile for:	newsfetch
# Date created:		12 September 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	newsfetch
PORTVERSION=	1.21
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/news/readers

MAINTAINER=	knu@FreeBSD.org

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man"

MAN1=		newsfetch.1
MANCOMPRESSED=	maybe

do-configure:
	cd ${WRKSRC} && ( \
	${ECHO} "PROG= newsfetch"; \
	${ECHO} "SRCS=" *.c; \
	${ECHO} ".include <bsd.prog.mk>"; \
	) > Makefile

.include <bsd.port.mk>
