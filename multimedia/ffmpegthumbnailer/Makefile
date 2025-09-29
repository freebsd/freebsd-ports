PORTNAME=	ffmpegthumbnailer
DISTVERSION=	2.2.3
CATEGORIES=	multimedia graphics

PATCH_SITES=	https://github.com/dirkvdb/ffmpegthumbnailer/commit/
PATCHFILES=	df789ec326ae0f2c619f91c8f2fc8b5e45b50a70.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight video thumbnailer that can be used by file managers
WWW=		https://github.com/dirkvdb/ffmpegthumbnailer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libpng.so:graphics/png

USES=		cmake:testing compiler:c++11-lib gnome jpeg localbase pathfix \
		pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dirkvdb

EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

CMAKE_TESTING_ON=	ENABLE_TESTS

CMAKE_OFF=	ENABLE_TESTS
CMAKE_ON=	ENABLE_GIO

OPTIONS_DEFINE=	THUMBNAILER
OPTIONS_DEFAULT=THUMBNAILER
OPTIONS_SUB=	yes

THUMBNAILER_DESC=	Register as a system thumbnailer

THUMBNAILER_CMAKE_BOOL=	ENABLE_THUMBNAILER

.include <bsd.port.mk>
