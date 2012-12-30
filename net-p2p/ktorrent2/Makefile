# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	2.2.8
PORTREVISION=	6
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

LATEST_LINK=	${PORTNAME}2

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|zeroconf||' ${WRKSRC}/plugins/Makefile.in

.include <bsd.port.mk>
