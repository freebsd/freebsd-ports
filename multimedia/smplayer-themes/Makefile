# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer-themes
PORTVERSION=	16.8.0
PORTEPOCH=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/smplayer/SMPlayer-themes/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Themes for SMPlayer

USES=		qt:4 tar:bzip2
USE_QT=		rcc_build
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/smplayer

PORTDOCS=	Changelog README.txt
OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
