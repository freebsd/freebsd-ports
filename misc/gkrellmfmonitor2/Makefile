# New ports collection makefile for:	gkrellmfmonitor2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.2 2002/11/24 02:30:34 jylefort Exp $
#

PORTNAME=	gkrellmfmonitor
PORTVERSION=	2.0.4
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://makovick.googlepages.com/
DISTNAME=	gkrellm-fmonitor-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM FMonitor plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmfmonitor2

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -fPIC"
ALL_TARGET=	fmonitor.so

PLIST_FILES=	libexec/gkrellm2/plugins/fmonitor.so

do-install:
	@${MKDIR} ${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_DATA} ${WRKSRC}/fmonitor.so ${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
