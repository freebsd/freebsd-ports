# $FreeBSD$

PORTNAME=	minitube
DISTVERSION=	3.6.7
CATEGORIES=	multimedia www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TV-like client for YouTube

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++11-lang gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
GH_TUPLE=	\
		flaviotordini:idle:6aa092da64a011e445bf31cf31c0cd8dda4c64ff:flaviotordini_idle/lib/idle \
		flaviotordini:media:65afcf5864677707ecf5692ef7f53e3dbdc50678:flaviotordini_media/lib/media \
		flaviotordini:http:b85c56407733f6f562f6cb25df137611f843f114:flaviotordini_http/lib/http \
		flaviotordini:updater:18ce1d09fda792d9f4bb8fe91409a79cdae84fe1:flaviotordini_updater/lib/updater \
		flaviotordini:js:13c95447a7c5f6854e00c6749f90488a37696721:flaviotordini_js/lib/js

USE_GL=		gl
USE_QT=		core dbus declarative gui network script sql widgets \
		buildtools_build imageformats_run sql-sqlite3_run \
		x11extras

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE} \
		DEFINES+=APP_GOOGLE_API_KEY="${MINITUBE_GOOGLE_API_KEY}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USE=	QT=linguisttools_build

post-patch:
# Remove BOM
	@${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/src/aggregatevideosource.cpp

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/minitube.pro

.include <bsd.port.mk>
