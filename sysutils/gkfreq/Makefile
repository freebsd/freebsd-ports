# New ports collection makefile for:	gkfreq
# Date Created:		Jun 18 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkfreq
PORTVERSION=	0.1.1
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.peakunix.net/downloads/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A plugin for gkrellm2 which displays the current CPU speed

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

PLIST_FILES=	libexec/gkrellm2/plugins/gkfreq.so

USE_X_PREFIX=	yes

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
