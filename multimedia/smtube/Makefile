# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtube
PORTVERSION=	16.7.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/smtube/SMTube/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	SMPlayer YouTube browser

RUN_DEPENDS=	smplayer:multimedia/smplayer

USES=		gmake tar:bzip2
ALL_TARGET=	#empty
USE_QT4=	linguisttools_build moc_build qmake_build \
		rcc_build script uic_build webkit
MAKE_ARGS=	DATA_PATH=${DATADIR} DOC_PATH=${DOCSDIR} \
		LRELEASE=${LRELEASE} MAKE=${MAKE_CMD}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^QMAKE/ s|qmake|${QMAKE} ${QMAKE_ARGS:S,\$(,\$\$(,g}|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
