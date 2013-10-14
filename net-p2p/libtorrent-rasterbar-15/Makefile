# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
PORTVERSION=	0.15.9
PORTREVISION?=	4
CATEGORIES?=	net-p2p ipv6
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	libtorrent
PKGNAMESUFFIX=	-15

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	C++ library implementing a BitTorrent client

BROKEN=		Does not build with recent boost


CONFLICTS+=	libtorrent-rasterbar-0.1[46789].*

BUILD_DEPENDS=	pkgconf>0:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS+=	boost_date_time:${PORTSDIR}/devel/boost-libs \
		GeoIP.5:${PORTSDIR}/net/GeoIP

USES=	pathfix
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
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
		--with-openssl=${OPENSSLBASE} \
		--with-zlib=system

USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes" && defined(USE_PYTHON)
CONFIGURE_ARGS+=	--enable-python-binding \
			--with-boost-python=boost_python
.else
CONFIGURE_ARGS+=	--disable-python-binding
.endif

pre-patch:
	@${MV} ${WRKSRC}/include/libtorrent/alloca.hpp \
	    ${WRKSRC}/include/libtorrent/alloca.hpp.Dist
	@${SED} -e 's#alloca.h#stdlib.h#g' \
	    ${WRKSRC}/include/libtorrent/alloca.hpp.Dist > \
	    ${WRKSRC}/include/libtorrent/alloca.hpp
	@${CP} ${WRKSRC}/configure ${WRKSRC}/configure.Dist
	@${SED} -e 's#COMPILETIME_OPTIONS+="#COMPILETIME_OPTIONS="$$COMPILETIME_OPTIONS #g' \
	    ${WRKSRC}/configure.Dist > ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's:BOOST_FILESYSTEM_VERSION=2:BOOST_FILESYSTEM_VERSION=3:g' \
		-e 's:BOOST_FILESYSTEM_VERSION 2:BOOST_FILESYSTEM_VERSION 3:g' \
		-e 's:\[BOOST_FILESYSTEM_VERSION\],\[2\]:[BOOST_FILESYSTEM_VERSION],[3]:g' \
		${WRKSRC}/bindings/python/setup.py \
		${WRKSRC}/configure \
		${WRKSRC}/Jamfile \
		${WRKSRC}/libtorrent-rasterbar-cmake.pc \
		${WRKSRC}/libtorrent-rasterbar.pc


.if defined(SLAVE_PORT) && ${SLAVE_PORT:L}=="yes"
post-patch: slave-post-patch
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
