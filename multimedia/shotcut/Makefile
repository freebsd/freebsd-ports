# $FreeBSD$

PORTNAME=	shotcut
DISTVERSIONPREFIX=	v
DISTVERSION=	${FULLVERSION}
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open source, cross-platform video editor

LICENSE=	GPLv3

LIB_DEPENDS=	libmlt.so:multimedia/mlt
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${LOCALBASE}/lib/libjack.so:audio/jack

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig \
		qmake qt:5 sdl shared-mime-info \
		xorg

USE_GITHUB=	yes
GH_ACCOUNT=	mltframework

# Needed to be able to correctly check for updates in-app.
FULLVERSION=	21.02.27

USE_GL+=	gl
USE_QT=		buildtools_build concurrent_build core declarative \
		graphicaleffects_run gui multimedia network opengl \
		printsupport quickcontrols2 sql \
		sql-sqlite3_run webkit websockets widgets x11extras xml \
		linguisttools_build
USE_SDL=	sdl2
USE_XORG=	x11
QMAKE_ARGS=	${PORTNAME:tu}_VERSION="${FULLVERSION}"

OPTIONS_DEFINE=	FREI0R LADSPA NLS WEBVFX
OPTIONS_DEFAULT=FREI0R LADSPA WEBVFX
OPTIONS_SUB=	yes

WEBVFX_DESC=	HTML/QML-based video effects support

FREI0R_RUN_DEPENDS=	frei0r-plugins>=0:graphics/frei0r-plugins

LADSPA_RUN_DEPENDS=	swhplugins>=0:audio/swhplugins

WEBVFX_RUN_DEPENDS=	${LOCALBASE}/lib/mlt/libmltwebvfx.so:multimedia/webvfx-qt5

pre-build:
	@${FIND} ${WRKSRC} -name '.depend' -delete

.include <bsd.port.mk>
