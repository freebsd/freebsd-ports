# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
DISTVERSION=	0.13svn.r2335
CATEGORIES=	net-p2p
MASTER_SITES=	SF/qbittorrent
PKGNAMEPREFIX=	rb
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client (devel version)

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFLICTS=	libtorrent-[0-9]* \
		libtorrent-devel-[0-9]* \
		rblibtorrent-[0-9]*

post-install:
	@cd ${PREFIX}/lib && ${LN} -sf libtorrent-0.13.so libtorrent.so.2 && \
		${LN} -sf libtorrent.so.2 libtorrent.so

.include <bsd.port.mk>
