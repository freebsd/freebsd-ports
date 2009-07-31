# New ports collection makefile for:	gkrellshoot2
# Date Created:			28 Jan 2003
# Whom:				Andrew Stuart <elitetek@tekrealm.net>
#
# $FreeBSD$
#

PORTNAME=	gkrellshoot
PORTVERSION=	0.4.4
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A screen locking and screen capture plugin for GKrellM 2

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2 \
		import:${PORTSDIR}/graphics/ImageMagick

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellshoot.so
WRKSRC=		${WRKDIR}/gkrellShoot-${PORTVERSION}

ALL_TARGET=	${PORTNAME}.so

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
