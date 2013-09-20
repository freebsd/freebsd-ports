# Created by: Alexander Gromnizki
# $FreeBSD$

PORTNAME=	tidyup-mail
PORTVERSION=	0.12
CATEGORIES=	russian mail
MASTER_SITES=	http://gromnizki.unixdev.net/soft/

MAINTAINER=	gromnizki@unixdev.net
COMMENT=	Remove unsafe characters from email & make xterm happy

MAN1=		${PORTNAME}.1
MANLANG=	ru.KOI8-R

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/tidyup-mail

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/ru.KOI8-R/man1/

.include <bsd.port.mk>
