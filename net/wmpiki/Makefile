# New ports collection makefile for:    wmpiki
# Date created:         19 February 2004
# Whom:                 Thomas Kempka <t.kempka@web.de>
#
# $FreeBSD$
#

PORTNAME=	wmpiki
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	net windowmaker
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	t.kempka@web.de
COMMENT=	A multiping host checker dockapp

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	xpm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$$(X11BASE)|g' \
		-e 's|/include/X11|/include|g' \
		-e 's|gcc|cc|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|ping_options\=-c 1 -w 1|ping_options\=-c 1 -i 1|g' \
		-e 's|ping host -c 1 -w 1|ping host -c 1 -i 1|g' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|ping_options\=-c 1 -w 1|ping_options\=-c 1 -i 1|g' \
		${WRKSRC}/config.example

do-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/wmpiki ${PREFIX}/bin

.include <bsd.port.mk>
