# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
DISTVERSION=	0.12rc3
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.rasterbar.com/products/libtorrent/
PKGNAMEPREFIX=	rb
PKGNAMESUFFIX=	-devel

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client

LIB_DEPENDS=	boost_date_time.3:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/rc[[:digit:]]//}

CONFLICTS=	libtorrent-[0-9]* \
		libtorrent-devel-[0-9]* \
		rblibtorrent-[0-9]*

.include <bsd.port.mk>
