# New ports collection makefile for:	gkrellm-gift
# Date created:		Mon May  3 08:48:47 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	gift
PORTVERSION=	0.2.3
PORTREVISION=	10
CATEGORIES=	net-p2p
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/gkrellm-gift/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}giFT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM2 plugin that monitors active giFT transfers

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2
BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	libexec/gkrellm2/plugins/gift.la \
		libexec/gkrellm2/plugins/gift.so

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/libexec/gkrellm2/plugins/${PORTNAME}.so

.include <bsd.port.mk>
