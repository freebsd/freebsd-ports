# New ports collection makefile for:	gkrellm-gift
# Date created:		Mon May  3 08:48:47 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	gift
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/gkrellm-gift/ \
		http://depot.fsck.ch/mirror/distfiles/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}giFT-${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin that monitors active giFT transfers

LIB_DEPENDS=	gift.0:${PORTSDIR}/net/gift
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_X_PREFIX=	yes
PLIST_FILES=	libexec/gkrellm2/plugins/gift.so

post-install:
	${STRIP_CMD} ${PREFIX}/libexec/gkrellm2/plugins/${PORTNAME}.so

.include <bsd.port.mk>
