# Created by: Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	newsfetch
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/news/readers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download news articles from NNTP server

MAKE_ENV=	BINDIR="${PREFIX}/bin" MANDIR="${PREFIX}/man/man"

USES=		uidfix
CFLAGS+=	-Wno-return-type
PLIST_FILES=	bin/newsfetch \
		man/man1/newsfetch.1.gz

do-configure:
	cd ${WRKSRC} && ( \
	${ECHO_CMD} "PROG= newsfetch"; \
	${ECHO_CMD} "SRCS=" *.c; \
	${ECHO_CMD} ".include <bsd.prog.mk>"; \
	) > Makefile

.include <bsd.port.mk>
