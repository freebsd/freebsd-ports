# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${PORTVERSION}/ \
		http://www.brueffer.de/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CONFLICTS=	ktorrent-devel-[0-9]*
LATEST_LINK=	${PORTNAME}2

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|zeroconf||' ${WRKSRC}/plugins/Makefile.in

.include <bsd.port.mk>
