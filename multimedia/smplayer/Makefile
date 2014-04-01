# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
DISTVERSION=	14.3.0
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Complete front-end based on Qt4 for mplayer

LICENSE=	GPLv2

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		smplayer-skins>=0:${PORTSDIR}/multimedia/smplayer-skins \
		smplayer-themes>=0:${PORTSDIR}/multimedia/smplayer-themes

USE_QT4=	gui network script xml moc_build rcc_build uic_build \
		uic3_build porting_build linguist_build

ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}

USES=		desktop-file-utils dos2unix gmake qmake tar:bzip2
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes

PORTDOCS=	Changelog Not_so_obvious_things.txt Readme.txt \
		Release_notes.txt Watching_TV.txt
OPTIONS_DEFINE=	DOCS DEBUG

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|&& $$(QMAKE) $$(QMAKE_OPTS)||; \
		s|lrelease|${LRELEASE}|; \
		s|/share/man|/man|g; \
		s| make| ${MAKE_CMD}|g' \
		${WRKSRC}/Makefile

.if ${PORT_OPTIONS:MDEBUG}
	@${REINPLACE_CMD} -e '/CONFIG += debug/s|#||' \
		${WRKSRC}/src/smplayer.pro
.else
	@${REINPLACE_CMD} -e '/DEFINES += NO_DEBUG_ON_CONSOLE/s|#||' \
		${WRKSRC}/src/smplayer.pro
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
