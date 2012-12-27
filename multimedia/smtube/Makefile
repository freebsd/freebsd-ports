# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smtube
PORTVERSION=	1.5
CATEGORIES=	multimedia
MASTER_SITES=	SF/smplayer/SMTube/${PORTVERSION}/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	SMPlayer YouTube browser

RUN_DEPENDS=	${LOCALBASE}/bin/smplayer:${PORTSDIR}/multimedia/smplayer
LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	#empty
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xrender
USE_QT4=	linguist_build moc_build qmake_build rcc_build uic_build \
		corelib gui network xml
INSTALLS_ICONS=	yes

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|g' \
		-e 's|lrelease|${QT_PREFIX}/bin/lrelease-qt4|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		-e 's|$$(PREFIX)/share/smtube|${DATADIR}|g' \
		-e 's| make| ${GMAKE}|' \
		${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|$$(PREFIX)/share/doc/smtube|${DOCSDIR}|' \
		${WRKSRC}/Makefile
.else
	@${REINPLACE_CMD} -e '/DOC_PATH/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
