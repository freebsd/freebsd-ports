PORTNAME=	minitube
DISTVERSION=	3.9.2
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
		flaviotordini:http:68b9cf0:flaviotordini_http/lib/http \
		flaviotordini:idle:6aa092d:flaviotordini_idle/lib/idle \
		flaviotordini:js:c026465:flaviotordini_js/lib/js \
		flaviotordini:media:b2f5678:flaviotordini_media/lib/media \
		flaviotordini:promises:e6e5653:flaviotordini_promises/lib/promises \
		flaviotordini:updater:17b8f7b:flaviotordini_updater/lib/updater

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
