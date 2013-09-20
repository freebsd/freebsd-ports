# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	gkrellmlaunch
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application launcher plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PORTSCOUT=	ignore:1

PLIST_FILES=	libexec/gkrellm/plugins/gkrellmlaunch.so
USE_GNOME=	imlib
ALL_TARGET=	${PORTNAME}.so

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.post.mk>
