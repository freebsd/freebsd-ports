# $FreeBSD$

PORTNAME=	shotcut
PORTVERSION=	${FULLVERSION:R}
CATEGORIES=	multimedia

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Free, open source, cross-platform video editor

LICENSE=	GPLv3

LIB_DEPENDS=	libmlt.so:multimedia/mlt
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/lib/libjack.so.0:audio/jack \
		${LOCALBASE}/lib/libSDL-1.2.so.0:devel/sdl12

USE_GITHUB=	yes
GH_ACCOUNT=	mltframework
GH_TAGNAME=	v${PORTVERSION}
# Needed to be able to correctly check for updates in-app.
FULLVERSION=	16.12.03

USES=		pkgconfig qmake
USE_QT5=	buildtools_build concurrent_build core \
		graphicaleffects_run gui multimedia network opengl \
		printsupport qml quick quickcontrols_run sql \
		sql-sqlite3_run webkit websockets widgets x11extras xml
USE_XORG=	x11
QMAKE_ARGS=	${PORTNAME:tu}_VERSION="${FULLVERSION}"
DESKTOP_ENTRIES="Shotcut" \
		"Video Editor" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"AudioVideo;Video;AudioVideoEditing;" \
		""

OPTIONS_DEFINE=	FREI0R LADSPA NLS WEBVFX
OPTIONS_DEFAULT=FREI0R LADSPA WEBVFX
OPTIONS_SUB=	yes

WEBVFX_DESC=	HTML/QML-based video effects support

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

NLS_USE=		QT5=linguisttools_build

WEBVFX_RUN_DEPENDS=	${LOCALBASE}/lib/mlt/libmltwebvfx.so:multimedia/webvfx-qt5

post-patch:
	${REINPLACE_CMD} -e 's/"qmelt"/"melt"/' \
		${WRKSRC}/src/jobs/meltjob.cpp

pre-build:
	@${FIND} ${WRKSRC} -name '.depend' -delete

post-build-NLS-on:
	${LRELEASE} ${WRKSRC}/src/src.pro

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/icons/${PORTNAME}-logo-64.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png

post-install-NLS-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm \
		${STAGEDIR}${DATADIR}/translations

.include <bsd.port.mk>
