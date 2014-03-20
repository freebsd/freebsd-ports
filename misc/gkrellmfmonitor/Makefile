# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gkrellmfmonitor
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	misc
MASTER_SITES=	# none
DISTNAME=	fmonitor-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM FMonitor plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/fmonitor.so
PLIST_DIRSTRY=	libexec/gkrellm/plugins libexec/gkrellm

USE_GNOME=	imlib
ALL_TARGET=	fmonitor.so
CFLAGS+=	-fPIC `${GTK_CONFIG} --cflags` `imlib-config --cflags-gdk`
MAKE_ARGS=	CC="${CC} ${CFLAGS}" GTK_LIB="`${GTK_CONFIG} --libs`"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_LIB} ${WRKSRC}/fmonitor.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
