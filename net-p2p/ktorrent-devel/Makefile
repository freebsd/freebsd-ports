# New ports collection makefile for:	ktorrent-devel
# Date created:				Sun Jul 30 01:14:55 CEST 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	20071023
PORTREVISION=	3
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://www.brueffer.de/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	markus@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CONFLICTS=	ktorrent-[0.9]*

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|zeroconf||' ${WRKSRC}/src/plugins/Makefile.in

.include <bsd.port.mk>
