# New ports collection makefile for:	gkrellm-xkb
# Date Created:				Jun 24 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	gkrellm-xkb
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	misc x11
MASTER_SITES=	http://www.sweb.cz/tripie/gkrellm/xkb/dist/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	X keyboard layout plugin for GKrellM

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/xkb.so
USE_X_PREFIX=	yes
MAKE_ENV=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins
ALL_TARGET=	xkb.so

.include <bsd.port.mk>
