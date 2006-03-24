# New ports collection makefile for:   rblibtorrent
# Date created:        5 February 2006
# Whom:                Johan Ström <johan@stromnet.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.9.1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=libtorrent
PKGNAMEPREFIX=	rb

MAINTAINER=	johan@stromnet.org
COMMENT=	A C++ library implementing a BitTorrent client

LIB_DEPENDS=	boost_date_time.3:${PORTSDIR}/devel/boost \
		boost_filesystem.3:${PORTSDIR}/devel/boost \
		boost_thread.3:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFLICTS=	libtorrent-[0-9]*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	is unsupported on FreeBSD < 5
.endif

.include <bsd.port.post.mk>
