# New ports collection makefile for:	gkrellm-mailwatch
# Date Created:		22.08.2000
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	gkrellmmailwatch
PORTVERSION= 	0.2
CATEGORIES=	mail
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	mailwatch-${PORTVERSION}

MAINTAINER=	treif@mayn.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
IMLIB_CONFIG?=	${X11BASE}/bin/imlib-config
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}" IMLIB_CONFIG="${IMLIB_CONFIG}"

WRKSRC=		${WRKDIR}/mailwatch

do-install:
		${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
		${INSTALL_PROGRAM} ${WRKSRC}/mailwatch.so ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
