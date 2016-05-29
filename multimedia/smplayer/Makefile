# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
DISTVERSION=	16.4.0
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Complete front-end based on Qt4 for mplayer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Copying.txt

RUN_DEPENDS=	mplayer:multimedia/mplayer \
		smplayer-skins>=0:multimedia/smplayer-skins \
		smplayer-themes>=0:multimedia/smplayer-themes

USE_QT4=	gui dbus network script xml moc_build rcc_build uic_build \
		uic3_build porting_build linguisttools_build

ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}

USES=		cpe desktop-file-utils dos2unix gmake qmake tar:bzip2
CPE_VENDOR=	ricardo_villalba
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes

PORTDOCS=	Changelog Not_so_obvious_things.txt Notes_about_mpv.txt \
		Readme.txt Release_notes.txt Watching_TV.txt
OPTIONS_DEFINE=	DOCS DEBUG

# Do not use unstable versions
PORTSCOUT=	site:http://sourceforge.net/projects/smplayer/files/Unstable/releases/

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
