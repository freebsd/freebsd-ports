PORTNAME=	trafficserver
DISTVERSION=	10.1.0
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Fast, scalable and extensible HTTP proxy server
WWW=		https://trafficserver.apache.org/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libcjose.so:devel/cjose \
		libhwloc.so:devel/hwloc2 \
		libjansson.so:devel/jansson \
		libpcre.so:devel/pcre \
		libpcre2-8.so:devel/pcre2 \
		libunwind-ptrace.so:devel/libunwind

USES=		cmake compiler:c++20-lang cpe libtool localbase luajit \
		ncurses ninja pathfix perl5 pkgconfig ssl tar:bzip2
CPE_VENDOR=	apache
CPE_PRODUCT=	traffic_server
USE_LDCONFIG=	yes
USE_PERL5=	build run
USE_RC_SUBR=	${PORTNAME}

CMAKE_BUILD_TYPE=	release
CMAKE_ARGS+=	-DENABLE_EVENT_TRACKER=1 \
				-DENABLE_URI_SIGNING=1 \
				-DBUILD_EXPERIMENTAL_PLUGINS=1 \
				-DWITH_USER=${USERS} \
				-DWITH_GROUP=${GROUPS}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" \
		PORTVERSION="${DISTVERSION}" \
		ARCH="${ARCH:C/powerpc64.*/powerpc/}" \
		CMAKE_BUILD_TYPE="${CMAKE_BUILD_TYPE}"

OPTIONS_DEFINE=	GEOIP IMAGEMAGICK MIMALLOC X11
OPTIONS_SUB=	yes

IMAGEMAGICK_DESC=		Enable ats-magick & webp convert plugin
IMAGEMAGICK_CMAKE_OFF=	-DENABLE_MAGICK=OFF
GEOIP_DESC=			Enable MaxMindDB-based GeoIP geolocation support
MIMALLOC_DESC=			Use mimalloc

GEOIP_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
GEOIP_CMAKE_OFF=	-DENABLE_MAXMIND_ACL=OFF -DENABLE_GEOIP_ACL=OFF
MIMALLOC_LIB_DEPENDS=		libmimalloc.so:devel/mimalloc
MIMALLOC_CMAKE_ON=	-DENABLE_MIMALLOC=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick:run
.else
USES+=		magick:run,nox11
.endif
.endif

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/snapshots
	(cd ${STAGEDIR}${ETCDIR} && for f in *.config *.yaml; do ${MV} $$f $$f.sample; done)
	${RM} -r ${STAGEDIR}${PREFIX}/var
	${MKDIR} ${STAGEDIR}/var/cache/trafficserver
	${MKDIR} ${STAGEDIR}/var/log/trafficserver
	${MKDIR} ${STAGEDIR}/var/run/trafficserver

.include <bsd.port.mk>
