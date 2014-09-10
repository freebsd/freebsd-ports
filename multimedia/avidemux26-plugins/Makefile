# Created by: Anish Mistry (with help from mean)
# $FreeBSD$

PORTNAME=	avidemux26
PORTVERSION=	${AVIDEMUX2_VERSION}
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMESUFFIX=	-plugins

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor (Plugins)

LIB_DEPENDS=	libADM6avutil.so.52:${PORTSDIR}/multimedia/avidemux26

MASTERDIR=	${.CURDIR}/../avidemux26
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile.common"

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_plugins

#CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}" -DAVIDEMUX_CORECONFIG_DIR=${CONFIGURE_WRKSRC}/config
CMAKE_ARGS+=	-DAVIDEMUX_SOURCE_DIR=${WRKSRC} -DAVIDEMUX_INSTALL_PREFIX:PATH="${PREFIX}"
CMAKE_ARGS+=	-DPLUGIN_UI=ALL

.if ${PORT_OPTIONS:MCLI}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/cli/config.h:${PORTSDIR}/multimedia/avidemux26-cli
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/cli/config.h:${PORTSDIR}/multimedia/avidemux26-cli
.endif

.if ${PORT_OPTIONS:MQT4}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/qt4/config.h:${PORTSDIR}/multimedia/avidemux26-qt4
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/qt4/config.h:${PORTSDIR}/multimedia/avidemux26-qt4
.endif

.if ${PORT_OPTIONS:MGTK3}
BUILD_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/gtk/config.h:${PORTSDIR}/multimedia/avidemux26-gtk
RUN_DEPENDS+=	${LOCALBASE}/include/avidemux/2.6/gtk/config.h:${PORTSDIR}/multimedia/avidemux26-gtk
.endif

post-configure: post-configure-common

.include <bsd.port.post.mk>
