# Created by: Anish Mistry (with help from mean)
# $FreeBSD$

PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-plugins

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (Plugins)

LIB_DEPENDS=	libADM6avutil.so.56:multimedia/avidemux

MASTERDIR=	${.CURDIR}/../avidemux
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_plugins

#CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}" -DAVIDEMUX_CORECONFIG_DIR=${CONFIGURE_WRKSRC}/config
CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"
PLUGIN_UI=	COMMON SETTINGS

.if ${PORT_OPTIONS:MCLI}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.7/cli/config.h:multimedia/avidemux-cli
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.7/cli/config.h:multimedia/avidemux-cli
PLUGIN_UI+=	CLI
.endif

.if ${PORT_OPTIONS:MQT5}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.7/qt5/config.h:multimedia/avidemux-qt5 	 
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.7/qt5/config.h:multimedia/avidemux-qt5 	 
PLUGIN_UI+=	QT4
.endif

CMAKE_ARGS+=	-DPLUGIN_UI="${PLUGIN_UI}"

post-configure: post-configure-common

.include <bsd.port.post.mk>
