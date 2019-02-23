# $FreeBSD$

PORTNAME=	shotcut
DISTVERSIONPREFIX=	v
DISTVERSION=	${FULLVERSION}
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open source, cross-platform video editor

LICENSE=	GPLv3

LIB_DEPENDS=	libmlt.so:multimedia/mlt
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/lib/libjack.so:audio/jack \
		${LOCALBASE}/lib/libSDL.so:devel/sdl12

USE_GITHUB=	yes
GH_ACCOUNT=	mltframework
# Needed to be able to correctly check for updates in-app.
FULLVERSION=	18.11.18

USES=		pkgconfig qmake qt:5
USE_QT=		buildtools_build concurrent_build core declarative \
		graphicaleffects_run gui multimedia network opengl \
		printsupport quickcontrols_run sql \
		sql-sqlite3_run webkit websockets widgets x11extras xml
USE_SDL=	sdl2
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

NLS_USES=	qt:5
NLS_USE=		QT=linguisttools_build

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

.include <bsd.port.mk>
