# New ports collection makefile for:	mguesser
# Date created:			Jun 15, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	mguesser
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.mnogosearch.org/guesser/

MAINTAINER=	markp@FreeBSD.org

WRKSRC=		${WRKDIR}/guesser
CFLAGS+=	-DUDM_GUESSER_STANDALONG -DLMDIR=\"${PREFIX}/share/mguesser\"
MAKE_ENV+=	CFLAGS="${$CFLAGS}"
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e \
		"s/^CC=.+//g; s|^CFLAGS=|CFLAGS+=|g; s|-Wall -g||g; \
		s|./maps|${PREFIX}/share/mguesser|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mguesser ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/mguesser
	${INSTALL_DATA} ${WRKSRC}/maps/*.lm ${PREFIX}/share/mguesser

.include <bsd.port.mk>
