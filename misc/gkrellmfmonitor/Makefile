# New ports collection makefile for:	gkrellmfmonitor
# Date Created:		08 Sep 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.2 2002/11/09 03:14:54 jylefort Exp $
#

PORTNAME=	gkrellmfmonitor
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# none
DISTNAME=	fmonitor-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM FMonitor plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/fmonitor.so
USE_X_PREFIX=	yes
USE_GNOME=	imlib

do-install:
	${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/fmonitor.so ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
