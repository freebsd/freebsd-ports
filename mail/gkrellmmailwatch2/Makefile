# New ports collection makefile for:	gkrellmmailwatch2
# Date Created:		24 Nov 2002
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
# $Id: Makefile,v 1.2 2002/11/24 02:50:45 jylefort Exp $
#

PORTNAME=	gkrellmmailwatch
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	gkrellm-mailwatch-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	GKrellM mailwatch plugin

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellm-mailwatch

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
