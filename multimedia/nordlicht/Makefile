PORTNAME=	nordlicht
PORTVERSION=	0.4.5
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create moodbars from video files
WWW=		https://nordlicht.github.io/

DEPRECATED=	Unmaintained for years upstream and fails to build with FFmpeg 6
EXPIRATION_DATE=2023-05-31

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4 \
		libpopt.so:devel/popt \
		libpng.so:graphics/png

USE_GITHUB=	yes

USES=		cmake pathfix pkgconfig shebangfix
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

SHEBANG_FILES=	utils/mpv-nordlicht

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindFFmpeg.cmake

post-install:
	@cd ${WRKSRC}/utils && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
