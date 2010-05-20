# New ports collection makefile for:	libtorrent-rasterbar-14
# Date created:				14 February 2010
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.14.10
CATEGORIES=	net-p2p ipv6
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	libtorrent

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	A C++ library implementing a BitTorrent client

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		GeoIP.5:${PORTSDIR}/net/GeoIP

MAKE_JOBS_SAFE=	yes

CONFLICTS=	libtorrent-rasterbar*-0.15.*

USE_GNOME=	gnomehack
USE_OPENSSL=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug \
		--disable-python-binding \
		--with-boost=${LOCALBASE} \
		--with-boost-asio=boost_system \
		--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--with-boost-regex=boost_regex \
		--with-boost-program-options=boost_program_options \
		--with-dht=on \
		--with-encryption=on \
		--with-libgeoip \
		--with-zlib=system
USE_LDCONFIG=	yes

CPPFLAGS=	${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on FreeBSD versions prior to 7.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|AM_CPPFLAGS|g' \
		 ${WRKSRC}/src/Makefile.am

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
