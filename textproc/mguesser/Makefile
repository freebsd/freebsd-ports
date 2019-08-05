# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	mguesser
PORTVERSION=	0.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.mnogosearch.org/guesser/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for guessing a text's charset and language

BROKEN=		unfetchable

post-patch:
	${REINPLACE_CMD} -E \
		"s/^CC=.+//g; s|^CFLAGS=|CFLAGS+=|g; s|-Wall -g||g; \
		s|./maps|${PREFIX}/share/mguesser|g; \
		s/0.3/0.4/" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mguesser ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/maps/*.lm ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
