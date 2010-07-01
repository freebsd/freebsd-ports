# New ports collection makefile for:	libtorrent-rasterbar-15
# Date created:				14 February 2010
# Whom:					dougb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.15.1
PORTREVISION?=	0
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	libtorrent

MAINTAINER=	dougb@FreeBSD.org
COMMENT?=	A C++ library implementing a BitTorrent client

MAKE_JOBS_SAFE=	yes

CONFLICTS+=	libtorrent-rasterbar-0.14.*

NO_LATEST_LINK=	yes

LIB_DEPENDS+=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		GeoIP.5:${PORTSDIR}/net/GeoIP

USE_GNOME=	gnomehack
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--disable-debug \
		--disable-static \
		--enable-dht \
		--enable-encryption \
		--enable-pool-allocators \
		--enable-deprecated-functions \
		--with-boost=${LOCALBASE} \
		--with-boost-system=boost_system \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-thread=boost_thread \
		--enable-geoip \
		--with-libgeoip \
		--with-zlib=system

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding \
			--with-boost-python=boost_python \
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes"
post-patch: slave-post-patch
.else
post-patch:
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes"
post-install: slave-post-install
.else
post-install:
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.png ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
