# Created by: KT Sin <ktsin@acm.org>
# $FreeBSD$

PORTNAME=	gkrellmwireless
PORTVERSION=	2.0.2
PORTREVISION=	13
CATEGORIES=	net
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ktsin@acm.org
COMMENT=	GKrellM wireless plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellmwireless
USE_XORG=	x11
USES=		gmake pkgconfig

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
