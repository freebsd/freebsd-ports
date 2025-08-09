PORTNAME=	trafficserver
DISTVERSION=	9.2.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Fast, scalable and extensible HTTP proxy server
WWW=		https://trafficserver.apache.org/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhwloc.so:devel/hwloc2 \
		libpcre.so:devel/pcre \
		libbrotlienc.so:archivers/brotli

USES=		compiler:c++17-lang cpe gmake gnome libtool localbase \
		luajit ncurses pathfix perl5 pkgconfig sqlite ssl tar:bzip2
CPE_VENDOR=	apache
CPE_PRODUCT=	traffic_server
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--localstatedir=/var \
		--with-user=${USERS} \
		--with-group=${GROUPS} \
		--disable-maintainer-mode \
		--disable-dependency-tracking \
		--enable-mime-sanity-check \
		--enable-experimental-plugins \
		--enable-event-tracker
INSTALL_TARGET=	install-strip
USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" \
		PORTVERSION="${DISTVERSION}" \
		ARCH="${ARCH}"

OPTIONS_DEFINE=	DOCS GEOIP IMAGEMAGICK MEMCACHED MIMALLOC WCCP X11
OPTIONS_SUB=	yes

IMAGEMAGICK_DESC=		Enable ats-magick & webp convert plugin
MEMCACHED_DESC=			Enable memcache & memcached_remap plugin
MIMALLOC_DESC=			Use mimalloc
WCCP_DESC=			Enable WCCPv2 protocol

GEOIP_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MIMALLOC_LIB_DEPENDS=		libmimalloc.so:devel/mimalloc
MIMALLOC_CONFIGURE_WITH=	mimalloc
WCCP_CONFIGURE_ENABLE=		wccp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick
.else
USES+=		magick:nox11
.endif
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/cachedir:/s,$${localstatedir}+,$${localstatedir}/cache+,' \
		-e '/runtimedir:/s,$${localstatedir}+,$${localstatedir}/run+,' \
		${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's/#ifdef HAVE_EVENTFD/#if defined(HAVE_EVENTFD) \&\& TS_USE_EPOLL == 1/' \
		${WRKSRC}/src/tscore/EventNotify.cc \
		${WRKSRC}/include/tscore/EventNotify.h

post-install:
	${RMDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/snapshots
	(cd ${STAGEDIR}${ETCDIR} && for f in *.config *.yaml; do ${MV} $$f $$f.sample; done)
	${SED} -i '' -e 's|^${STAGEDIR}||g' \
		${STAGEDIR}${PREFIX}/lib/perl5/${ARCH}-freebsd-thread-multi/auto/Apache/TS/.packlist

.include <bsd.port.mk>
