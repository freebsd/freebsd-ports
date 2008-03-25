# New ports collection makefile for:	gkrellm-wireless
# Date Created:			4 Mar 2002
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmwireless
PORTVERSION=	0.2.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM wireless plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

NO_LATEST_LINK=	yes

USE_GNOME=	imlib

PLIST_FILES=	libexec/gkrellm/plugins/wireless.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
