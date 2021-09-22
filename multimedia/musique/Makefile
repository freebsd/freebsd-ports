PORTNAME=	musique
DISTVERSION=	1.10.1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Music player built for speed, simplicity and style

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
GH_TUPLE=	\
		flaviotordini:http:b85c564:flaviotordini_http/lib/http \
		flaviotordini:idle:6aa092d:flaviotordini_idle/lib/idle \
		flaviotordini:js:13c9544:flaviotordini_js/lib/js \
		flaviotordini:media:65afcf5:flaviotordini_media/lib/media \
		flaviotordini:sharedcache:024e759:flaviotordini_sharedcache/lib/sharedcache \
		flaviotordini:updater:18ce1d0:flaviotordini_updater/lib/updater

USE_GL=		gl
USE_QT=		core dbus declarative gui network sql widgets buildtools_build

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE}

CXXFLAGS+=	`pkg-config --cflags taglib`

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

NLS_USE=	QT=linguisttools_build

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
