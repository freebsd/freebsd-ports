# New ports collection makefile for:	newsfetch
# Date created:		12 September 1997
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	newsfetch
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/news/readers

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Download news articles from NNTP server

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man"

MAN1=		newsfetch.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/newsfetch

do-configure:
	cd ${WRKSRC} && ( \
	${ECHO_CMD} "PROG= newsfetch"; \
	${ECHO_CMD} "SRCS=" *.c; \
	${ECHO_CMD} ".include <bsd.prog.mk>"; \
	) > Makefile

.include <bsd.port.mk>
