# New ports collection makefile for:	alltraxclock
# Date created:				11 Feb 2004
# Whom:					Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	alltraxclock
PORTVERSION=	2.0.2
PORTREVISION=	3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://perso.wanadoo.fr/alltrax/
DISTNAME=	${PORTNAME}2_0.2-1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An analog clock plugin for gkrellm2

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_REINPLACE=	yes
USE_X_PREFIX=	yes

ALL_TARGET=	alltraxclock.so
PLIST_FILES=	libexec/gkrellm2/plugins/alltraxclock.so
WRKSRC=		${WRKDIR}/${PORTNAME}2_0.2/

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|;s|-O2||;s|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alltraxclock.so ${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
