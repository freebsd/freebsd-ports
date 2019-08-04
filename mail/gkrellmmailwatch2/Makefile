# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gkrellmmailwatch
PORTVERSION=	2.4.3
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	http://gkrellm.luon.net/files/
PKGNAMESUFFIX=	2
DISTNAME=	gkrellm-mailwatch-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM mailwatch plugin

LICENSE=	GPLv2+

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellm-mailwatch

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

MAKE_ENV+=	PLUGIN_DIR=${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

PLIST_FILES=	libexec/gkrellm2/plugins/mailwatch.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins/mailwatch.so

.include <bsd.port.mk>
