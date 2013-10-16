# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wlan2eth
PORTVERSION=	1.3
CATEGORIES=	net security
MASTER_SITES=	http://www.willhackforsushi.com/code/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convert packet captures in 802.11 format to Ethernet format

LICENSE=	GPLv2

PORTDOCS=	THANKS
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS		=|CFLAGS	?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
