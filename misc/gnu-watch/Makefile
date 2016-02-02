# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	watch
DISTVERSION=	3.2.8
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/ \
		LOCAL/ehaupt
PKGNAMEPREFIX=	gnu-
DISTNAME=	procps-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GNU watch command

LICENSE=	GPLv2

USES=		ncurses
LDFLAGS+=	-lncurses

PLIST_FILES=	bin/${PKGBASE} man/man1/gnu-watch.1.gz

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/watch.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/${PKGBASE}.1

.include <bsd.port.mk>
