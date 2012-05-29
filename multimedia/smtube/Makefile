# New ports collection makefile for:	smtube
# Date created:		2012-05-17
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smtube
PORTVERSION=	1.1
CATEGORIES=	multimedia
MASTER_SITES=	SF/smplayer/SMTube/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	SMPlayer YouTube browser

RUN_DEPENDS=	${LOCALBASE}/bin/smplayer:${PORTSDIR}/multimedia/smplayer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	linguist_build moc_build qmake_build rcc_build uic_build \
		corelib gui network xml
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|g' \
		-e 's|lrelease|${QT_PREFIX}/bin/lrelease-qt4|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		-e 's|$$(PREFIX)/share/smtube|${DATADIR}|g' \
		${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|$$(PREFIX)/share/doc/smtube|${DOCSDIR}|' \
		${WRKSRC}/Makefile
PORTDOCS=	*
.else
	@${REINPLACE_CMD} -e '/DOC_PATH/d' ${WRKSRC}/Makefile
.endif

do-build:
	cd ${WRKSRC} && ${MAKE}

.include <bsd.port.mk>
