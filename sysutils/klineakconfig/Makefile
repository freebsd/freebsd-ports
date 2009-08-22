# New ports collection makefile for:	klineakconfig
# Date created:				5 July 2002
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	klineakconfig
PORTVERSION=	0.9
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/lineak/Klineakconfig/Klineakconfig-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configure lineakd through a KDE interface

LIB_DEPENDS=	lineak.8:${PORTSDIR}/sysutils/lineakd

USE_KDELIBS_VER=3
USE_XORG=	xkbfile
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|-ldl||;s|-O2||g;s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
