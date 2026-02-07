PORTNAME=	smplayer
DISTVERSION=	25.6.0
CATEGORIES=	multimedia audio kde
MASTER_SITES=	https://github.com/${PORTNAME}-dev/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		SF/${PORTNAME}/SMPlayer/${PORTVERSION:S/4/3/} \
		SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Complete front-end based on Qt for mplayer
WWW=		https://www.smplayer.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/Copying.txt

USES=		cpe compiler:c++11-lang desktop-file-utils dos2unix gl \
		gmake qmake qt:5 tar:bzip2 xorg
CPE_VENDOR=	ricardo_villalba
DOS2UNIX_GLOB=	*.md *.txt
USE_GL=		gl
USE_QT=		buildtools:build linguisttools:build \
		core dbus declarative gui network widgets xml
USE_XORG=	x11 xext

QMAKE_ARGS=	"DEFINES_DISABLED+=MPLAYER2_SUPPORT"
MAKE_ENV=	DESTDIR=${STAGEDIR} LRELEASE=${LRELEASE}
ALL_TARGET=	src/smplayer

SUB_FILES=	pkg-message

CONFIGURE_WRKSRC=	${WRKSRC}/src

PORTDOCS=	${DOCS:T}
DOCS=		old-docs/Changelog old-docs/dvdmenus.txt old-docs/Finding_subtitles.txt \
		old-docs/Not_so_obvious_things.txt old-docs/Release_notes.txt \
		old-docs/Watching_TV.txt README.md Readme.txt Release_notes.md

OPTIONS_DEFINE=		DOCS DEBUG SKINS THEMES
OPTIONS_DEFAULT=	MPV SKINS THEMES
OPTIONS_MULTI=		ENGINE
OPTIONS_MULTI_ENGINE=	MPLAYER MPV

ENGINE_DESC=	Multimedia engine
MPLAYER_DESC=	Allow to use MPlayer as multimedia engine
MPV_DESC=	Allow to use mpv as multimedia engine
SKINS_DESC=	Install additional skins
THEMES_DESC=	Install additional themes

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPLAYER_QMAKE_OFF=	"DEFINES_DISABLED+=MPLAYER_SUPPORT"

MPV_RUN_DEPENDS=	mpv:multimedia/mpv
MPV_QMAKE_OFF=		"DEFINES_DISABLED+=MPV_SUPPORT"

SKINS_RUN_DEPENDS=	smplayer-skins>=0:multimedia/smplayer-skins
THEMES_RUN_DEPENDS=	smplayer-themes>=0:multimedia/smplayer-themes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -W -Wall -Werror|${CFLAGS}|' \
		${WRKSRC}/webserver/Makefile
	@${REINPLACE_CMD} -e 's|^sed|#sed|' \
		${WRKSRC}/install_appdata.sh

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
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
