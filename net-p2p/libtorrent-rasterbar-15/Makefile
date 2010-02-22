# New ports collection makefile for:	libtorrent-rasterbar-15
# Date created:				14 February 2010
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.15.r4252
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	http://heanet.dl.sourceforge.net/project/qbittorrent/qbittorrent-unstable/
PKGNAMESUFFIX=	-devel
DISTVERSION=	0.15.svn.r4252

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client (devel version)

MAKE_JOBS_SAFE=	yes

CONFLICTS=	rblibtorrent-[0-9]* libtorrent-rasterbar-0.14.*

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		GeoIP.5:${PORTSDIR}/net/GeoIP

USE_GNOME=	gnomehack
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug \
		--enable-dht \
		--enable-encryption \
		--enable-pool-allocators \
		--disable-deprecated-functions \
		--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--enable-geoip \
		--with-libgeoip \
		--with-zlib=system \
		--disable-python-binding

USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
