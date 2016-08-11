# Created by: Matthew West <mwest@uct.ac.za>
# $FreeBSD$

PORTNAME=	icmpchat
PORTVERSION=	0.6
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple console-based chat that uses ICMP protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

USES=		ncurses

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Changes Problems Readme Todo

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2 -Wall -pedantic|${CFLAGS}|' \
		-e 's|-lcurses|${LDFLAGS} -lncurses|g' \
		-e' s|= gcc|?= gcc|;s|default|all|' ${WRKSRC}/Makefile
# Fix for GCC 4.2
	@${REINPLACE_CMD} -e \
		's|((uint8_t \*) data) +=|data += sizeof(uint8_t *) *|' \
			${WRKSRC}/sha256.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icmpchat ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
