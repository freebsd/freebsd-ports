# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	watch
DISTVERSION=	3.2.8
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/ \
		CRITICAL
PKGNAMEPREFIX=	gnu-
DISTNAME=	procps-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GNU watch command

LICENSE=	GPLv2

LDFLAGS+=	-lncurses

PLIST_FILES=	bin/${UNIQUENAME} man/man1/gnu-watch.1.gz

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${UNIQUENAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${UNIQUENAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/watch.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/${UNIQUENAME}.1

.include <bsd.port.mk>
