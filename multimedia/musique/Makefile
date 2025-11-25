PORTNAME=	musique
DISTVERSION=	1.12
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Music player built for speed, simplicity and style
WWW=		https://flavio.tordini.org/musique \
		https://github.com/flaviotordini/musique

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
GH_TUPLE=	\
		flaviotordini:http:e7689c1:flaviotordini_http/lib/http \
		flaviotordini:idle:8a8bbb7:flaviotordini_idle/lib/idle \
		flaviotordini:media:b0310b8:flaviotordini_media/lib/media \
		flaviotordini:qt-reusable-widgets:197e874:qt_reusable_widgets/lib/qt-reusable-widgets \
		flaviotordini:updater:081df10:flaviotordini_updater/lib/updater \
		flaviotordini:js:781170a:flaviotordini_js/lib/js \
		flaviotordini:sharedcache:eec981a4285c7b371aa9dc7f0074f03794e86a26:flaviotordini_sharedcache/lib/sharedcache \
		itay-grudev:SingleApplication:14e9d14675156d3b55473a3b085de0e2a9f75578:itay_grudev_SingleApplication/lib/singleapplication

USE_GL=		gl
USE_QT=		base declarative tools:build

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE}

CXXFLAGS+=	`pkg-config --cflags taglib`

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
