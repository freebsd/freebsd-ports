# New ports collection makefile for:	gkrellm-trayicons
# Date created:		Wed Jun 23 14:55:49 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	trayicons
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://depot.fsck.ch/mirror/distfiles/ \
		http://sweb.cz/tripie/gkrellm/trayicons/dist/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin to display definable icons as notifiers or launchers

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
PLIST_FILES=	libexec/gkrellm2/plugins/trayicons.so

ALL_TARGET=	trayicons.so

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CC) $$(FLAGS)|$$(CC) $$(CFLAGS)|g' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
