# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	gkrellm-xkb
PORTVERSION=	1.05
PORTREVISION=	10
CATEGORIES=	misc x11
MASTER_SITES=	http://www.sweb.cz/tripie/gkrellm/xkb/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X keyboard layout plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		pkgconfig
PLIST_FILES=	libexec/gkrellm2/plugins/xkb.so
MAKE_ENV=	PLUGIN_DIR=${PLUGINDIR}
ALL_TARGET=	xkb.so
PLUGINDIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

post-patch:
	@${REINPLACE_CMD} '/$$(CC)/ s|FLAGS|CFLAGS|' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${PLUGINDIR}

.include <bsd.port.mk>
