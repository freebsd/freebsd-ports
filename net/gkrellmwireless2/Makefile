# Created by: KT Sin <ktsin@acm.org>
# $FreeBSD$

PORTNAME=	gkrellmwireless
PORTVERSION=	2.0.2
PORTREVISION=	14
CATEGORIES=	net
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ktsin@acm.org
COMMENT=	GKrellM wireless plugin

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellmwireless
USES=		gmake pkgconfig xorg
USE_XORG=	x11

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
