# New ports collection makefile for:	gkrellm-reminder
# Date Created:				Sat Dec 15 01:56:45 EST 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	reminder
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	misc
# The original distribution site has gone walking. This site is the
# gkrellm website with a reference to the plugin, but only with version
# 2.0.0, not the original one - edwin 20021227
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/
PKGNAMEPREFIX=	gkrellm-

MAINTAINER=	pat@FreeBSD.org
COMMENT=	GKrellM plugin that reminds you of important events

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
USE_GNOME=	imlib

do-install:
	@${INSTALL_DATA} ${WRKSRC}/reminder.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
