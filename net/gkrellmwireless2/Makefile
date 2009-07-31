# New ports collection makefile for:	gkrellm-wireless
# Date Created:			17 Mar 2003
# Whom:				KT Sin <ktsin@acm.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmwireless
PORTVERSION=	2.0.2
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ktsin@acm.org
COMMENT=	GKrellM wireless plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellmwireless

USE_XORG=	x11
USE_GMAKE=	yes

.include <bsd.port.mk>
