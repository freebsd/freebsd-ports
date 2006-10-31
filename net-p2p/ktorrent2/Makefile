# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	2.0.3
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.pwsp.net/downloads/${PORTVERSION}/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

CONFLICTS=	ktorrent-devel-[0-9]*

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
