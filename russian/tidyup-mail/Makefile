# Created by: Alexander Gromnizki
# $FreeBSD$

PORTNAME=	tidyup-mail
PORTVERSION=	0.12
CATEGORIES=	russian mail
MASTER_SITES=	http://gromnizki.unixdev.net/soft/

MAINTAINER=	gromnizki@unixdev.net
COMMENT=	Remove unsafe characters from email & make xterm happy

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/tidyup-mail man/ru.KOI8-R/man1/tidyup-mail.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/ru.KOI8-R/man1

.include <bsd.port.mk>
