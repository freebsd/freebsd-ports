# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gkrellm-gamma
PORTVERSION=	2.03
PORTREVISION=	13
CATEGORIES=	misc
MASTER_SITES=	http://www.sweb.cz/tripie/gkrellm/gamma/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFree86 gamma correction plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		pkgconfig
USE_XORG=	x11 xxf86vm
PLIST_FILES=	libexec/gkrellm2/plugins/gamma.so
MAKE_ENV=	PLUGIN_DIR=${PLUGINDIR}
ALL_TARGET=	gamma.so
PLUGINDIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

pre-install:
	@${MKDIR} ${PLUGINDIR}

.include <bsd.port.mk>
