# Created by: Anish Mistry (with help from mean)
# $FreeBSD$

PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
PORTREVISION=	17
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-plugins

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (Plugins)

LIB_DEPENDS=	libADM6avutil.so.54:multimedia/avidemux

MASTERDIR=	${.CURDIR}/../avidemux
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_plugins

#CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}" -DAVIDEMUX_CORECONFIG_DIR=${CONFIGURE_WRKSRC}/config
CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"
CMAKE_ARGS+=	-DPLUGIN_UI=ALL

.if ${PORT_OPTIONS:MCLI}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/cli/config.h:multimedia/avidemux-cli
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/cli/config.h:multimedia/avidemux-cli
.endif

.if ${PORT_OPTIONS:MGTK3}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/gtk/config.h:multimedia/avidemux-gtk
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/gtk/config.h:multimedia/avidemux-gtk
.endif

post-configure: post-configure-common

.include <bsd.port.post.mk>
