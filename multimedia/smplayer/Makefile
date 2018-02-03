# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
DISTVERSION=	18.1.0
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Complete front-end based on Qt for mplayer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Copying.txt

USES=		cpe desktop-file-utils dos2unix gmake qmake tar:bzip2
USE_XORG=	x11
CPE_VENDOR=	ricardo_villalba
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes

ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}
QMAKE_ARGS=	"DEFINES_DISABLED+=MPLAYER2_SUPPORT"

PORTDOCS=	Changelog Not_so_obvious_things.txt \
		Readme.txt Release_notes.txt Watching_TV.txt

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_MULTI=		ENGINE
OPTIONS_MULTI_ENGINE=	MPLAYER MPV
OPTIONS_DEFINE=		DOCS DEBUG SKINS THEMES
OPTIONS_DEFAULT=	QT4 MPLAYER SKINS THEMES

TOOLKIT_DESC=	Qt toolkit version
ENGINE_DESC=	Multimedia engine
MPLAYER_DESC=	Allow to use MPlayer as multimedia engine
MPV_DESC=	Allow to use mpv as multimedia engine
SKINS_DESC=	Install additional skins
THEMES_DESC=	Install additional themes

QT4_USE=	qt4=moc_build,linguisttools_build,rcc_build,uic_build
QT4_USE+=	qt4=corelib,dbus,gui,network,script,xml

QT5_USE=	qt5=buildtools_build,linguisttools_build
QT5_USE+=	qt5=core,dbus,gui,network,script,widgets,xml

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPLAYER_QMAKE_OFF=	"DEFINES_DISABLED+=MPLAYER_SUPPORT"

MPV_RUN_DEPENDS=	mpv:multimedia/mpv
MPV_QMAKE_OFF=		"DEFINES_DISABLED+=MPV_SUPPORT"

SKINS_RUN_DEPENDS=	smplayer-skins>=0:multimedia/smplayer-skins
THEMES_RUN_DEPENDS=	smplayer-themes>=0:multimedia/smplayer-themes

# Do not use unstable versions
PORTSCOUT=	site:http://sourceforge.net/projects/smplayer/files/Unstable/releases/

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|&& $$(QMAKE) $$(QMAKE_OPTS)||; \
		s|lrelease|${LRELEASE}|; \
		s|/share/man|/man|g; \
		s| make| ${MAKE_CMD}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-O2 -W -Wall -Werror|${CFLAGS}|' \
		${WRKSRC}/webserver/Makefile

post-patch-DEBUG-on:
	@${REINPLACE_CMD} -e '/CONFIG += debug/s|#||' \
		${WRKSRC}/src/smplayer.pro

post-patch-DEBUG-off:
	@${REINPLACE_CMD} -e '/DEFINES += NO_DEBUG_ON_CONSOLE/s|#||' \
		${WRKSRC}/src/smplayer.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/simple_web_server

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
