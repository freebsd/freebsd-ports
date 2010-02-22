# New ports collection makefile for:	libtorrent-rasterbar-14
# Date created:				14 February 2010
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.14.8
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	http://libtorrent.googlecode.com/files/

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client

MAKE_JOBS_SAFE=	yes

CONFLICTS=	rblibtorrent-[0-9]* libtorrent-rasterbar*-0.15.*

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		GeoIP.5:${PORTSDIR}/net/GeoIP

USE_GNOME=	gnomehack
USE_OPENSSL=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug \
		--disable-python-binding \
		--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--with-boost-regex=boost_regex \
		--with-boost-program-options=boost_program_options \
		--with-asio=shipped \
		--with-dht=on \
		--with-encryption=on \
		--with-libgeoip \
		--with-zlib=system
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|AM_CPPFLAGS|g ; \
		 s|@BOOST_SYSTEM_LIB@||g' ${WRKSRC}/src/Makefile.am

post-configure:
	@${REINPLACE_CMD} -e 's|@BOOST_SYSTEM_LIB@|-lboost_system|' \
		${WRKSRC}/libtorrent-rasterbar.pc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
