# New ports collection makefile for:	gkrellmlaunch2
# Date Created:				23 Aug 2004
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	gkrellmlaunch
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER= 	hideo@lastamericanempire.com
COMMENT=	An application launcher plugin for GKrellM2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellmlaunch.so
ALL_TARGET=	${PORTNAME}.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellmlaunch.so ${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
