# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wlan2eth
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.willhackforsushi.com/code/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert packet captures in 802.11 format to Ethernet format

LICENSE=	GPLv2

USES=		tar:tgz
SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS		=|CFLAGS	?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/THANKS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
