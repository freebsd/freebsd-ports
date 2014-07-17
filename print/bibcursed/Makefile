# Created by: ijliao
# $FreeBSD$

PORTNAME=	bibcursed
PORTVERSION=	2.0.1
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple curses-based editor for BibTeX bibliography files

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/bibcursed man/man1/bibcursed.1.gz

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
