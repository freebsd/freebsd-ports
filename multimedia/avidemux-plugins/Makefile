PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
PORTREVISION=	9
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-plugins

PATCH_SITES=	https://github.com/mean00/avidemux2/commit/
# Fix build with x265 4.1
PATCHFILES+=	c16d32a67cdb012db093472ad3776713939a30d1.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (Plugins)

LIB_DEPENDS=	libADM6avutil.so.56:multimedia/avidemux

MASTERDIR=	${.CURDIR}/../avidemux
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_plugins

CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"
PLUGIN_UI=	COMMON SETTINGS

.if ${PORT_OPTIONS:MCLI}
BUILD_DEPENDS+=	avidemux-cli>0:multimedia/avidemux-cli
RUN_DEPENDS+=	avidemux-cli>0:multimedia/avidemux-cli
PLUGIN_UI+=	CLI
.endif

.if ${PORT_OPTIONS:MQT5}
BUILD_DEPENDS+=	avidemux-qt5>0:multimedia/avidemux-qt5
RUN_DEPENDS+=	avidemux-qt5>0:multimedia/avidemux-qt5
PLUGIN_UI+=	QT4
.endif

CMAKE_ARGS+=	-DPLUGIN_UI="${PLUGIN_UI}"

post-configure: post-configure-common

.include <bsd.port.post.mk>
