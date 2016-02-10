# Created by: ijliao
# $FreeBSD$

PORTNAME=	bibcursed
PORTVERSION=	2.0.1
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple curses-based editor for BibTeX bibliography files

USES=		ncurses tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/bibcursed man/man1/bibcursed.1.gz

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} \
		${PORTNAME}.c -o ${PORTNAME} ${LDFLAGS} -lncurses)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
