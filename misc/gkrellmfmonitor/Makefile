# New ports collection makefile for:	gkrellmfmonitor
# Date Created:		08 Sep 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gkrellmfmonitor
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://alice.nc.huji.ac.il/~arsen/
DISTNAME=	fmonitor-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@brutele.be

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
USE_IMLIB=	yes

do-install:
	${MKDIR} ${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/fmonitor.so ${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
