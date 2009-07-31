# New ports collection makefile for:	gkrellmlaunch
# Date Created:				Tue Nov  6 19:15:45 EST 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellmlaunch
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application launcher plugin for GKrellM

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

PLIST_FILES=	libexec/gkrellm/plugins/gkrellmlaunch.so
USE_GNOME=	imlib
ALL_TARGET=	${PORTNAME}.so

.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.post.mk>
