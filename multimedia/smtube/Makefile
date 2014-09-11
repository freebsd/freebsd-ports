# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtube
PORTVERSION=	14.8.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/smplayer/SMTube/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	SMPlayer YouTube browser

RUN_DEPENDS=	${LOCALBASE}/bin/smplayer:${PORTSDIR}/multimedia/smplayer

USES=		gmake tar:bzip2
ALL_TARGET=	#empty
USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build
INSTALLS_ICONS=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE} ${QMAKE_ARGS:S,\$(,\$\$(,g}|' \
		-e 's|lrelease|${LRELEASE}|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		-e 's|$$(PREFIX)/share/smtube|${DATADIR}|g' \
		-e 's|$$(PREFIX)/share/doc/smtube|${DOCSDIR}|' \
		-e 's| make| ${MAKE_CMD}|' \
		${WRKSRC}/Makefile
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}	

.include <bsd.port.mk>
