# Created by: Thomas Kempka <t.kempka@web.de>
# $FreeBSD$

PORTNAME=	wmpiki
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	net windowmaker
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	t.kempka@web.de
COMMENT=	Multiping host checker dockapp

USE_XORG=	xpm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$$(LOCALBASE)|g' \
		-e 's|/include/X11|/include|g' \
		-e 's|gcc|cc|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|ping_options\=-c 1 -w 1|ping_options\=-c 1 -i 1|g' \
		-e 's|ping host -c 1 -w 1|ping host -c 1 -i 1|g' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|ping_options\=-c 1 -w 1|ping_options\=-c 1 -i 1|g' \
		${WRKSRC}/config.example

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/wmpiki ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
