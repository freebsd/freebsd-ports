# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF
PKGNAMEPREFIX=	rb
PKGNAMESUFFIX=	-devel

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client (devel version)

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	3.4
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFLICTS=	libtorrent-[0-9]* \
		libtorrent-devel-[0-9]* \
		rblibtorrent-[0-9]*

.include <bsd.port.mk>
