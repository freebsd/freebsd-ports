# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer-themes
PORTVERSION=	20120919
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/smplayer/SMPlayer-themes/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Themes for SMPlayer

USE_BZIP2=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/smplayer

PORTDOCS=	Changelog

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
