# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.13
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	rb

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFLICTS=	libtorrent-[0-9]* \
		libtorrent-devel-[0-9]* \
		rblibtorrent-devel-[0-9]*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.x
.endif

post-install:
	@cd ${PREFIX}/lib && ${LN} -sf libtorrent-0.13.so libtorrent.so.1 && \
		${LN} -sf libtorrent.so.1 libtorrent.so

.include <bsd.port.post.mk>
