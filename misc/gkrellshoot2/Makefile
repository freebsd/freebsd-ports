# Created by: Andrew Stuart <elitetek@tekrealm.net>
# $FreeBSD$

PORTNAME=	gkrellshoot
PORTVERSION=	0.4.4
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/GkrellM2.0%20Port/${PORTVERSION}
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Screen locking and screen capture plugin for GKrellM 2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2 \
		import:graphics/ImageMagick

USES=		pkgconfig

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellshoot.so
WRKSRC=		${WRKDIR}/gkrellShoot-${PORTVERSION}

ALL_TARGET=	${PORTNAME}.so
PLUGINDIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

post-patch:
	@${REINPLACE_CMD} '/^CFLAGS/ s|= |= ${CFLAGS} |' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PLUGINDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${PLUGINDIR}

.include <bsd.port.mk>
