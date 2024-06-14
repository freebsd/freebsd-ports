PORTNAME=	musique
DISTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Music player built for speed, simplicity and style
WWW=		https://flavio.tordini.org/musique

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpv.so:multimedia/mpv \
		libtag.so:audio/taglib

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
GH_TUPLE=	\
		flaviotordini:http:39bfc6bb149d0b5a49ab966c824906e0523d161c:flaviotordini_http/lib/http \
		flaviotordini:idle:6aa092da64a011e445bf31cf31c0cd8dda4c64ff:flaviotordini_idle/lib/idle \
		flaviotordini:media:5443f81c52ac008a6de6593124d03ee41f772633:flaviotordini_media/lib/media \
		flaviotordini:updater:bbbf833531cd80bbd8a190fa1ae98a1f068c8d16:flaviotordini_updater/lib/updater \
		flaviotordini:js:deed5303b0b6a587c62be73a9bc198058964111c:flaviotordini_js/lib/js \
		flaviotordini:sharedcache:eec981a4285c7b371aa9dc7f0074f03794e86a26:flaviotordini_sharedcache/lib/sharedcache \
		itay-grudev:SingleApplication:14e9d14675156d3b55473a3b085de0e2a9f75578:itay_grudev_SingleApplication/lib/singleapplication

USE_GL=		gl
USE_QT=		core dbus declarative gui network sql widgets buildtools:build

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE}

CXXFLAGS+=	`pkg-config --cflags taglib`

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_SUB=		yes

NLS_USE=	QT=linguisttools:build

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
