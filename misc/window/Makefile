# Created by: Tom Rhodes <trhodes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	window
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~trhodes/

MAINTAINER=	trhodes@FreeBSD.org
COMMENT=	Window environment on ASCII terminals

LICENSE=	BSD

WRKSRC=		${WRKDIR}/window
CFLAGS+=	-Wno-return-type

MAN1=		window.1
PLIST_FILES=	bin/window

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/window ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
