PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.2.2
CATEGORIES=	multimedia graphics
MASTER_SITES=	https://github.com/dirkvdb/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libavformat.so:multimedia/ffmpeg

USES=		cmake compiler:c++11-lib gnome jpeg localbase pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

CMAKE_ON=	ENABLE_GIO

OPTIONS_DEFINE=	TEST THUMBNAILER
THUMBNAILER_DESC=Register as a system thumbnailer
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=THUMBNAILER

TEST_CMAKE_BOOL=	ENABLE_TESTS

THUMBNAILER_CMAKE_ON=	-DENABLE_THUMBNAILER:BOOL=ON

do-test:
	(cd ${TEST_WRKSRC} && CTEST_OUTPUT_ON_FAILURE=1 ctest)

.include <bsd.port.mk>
