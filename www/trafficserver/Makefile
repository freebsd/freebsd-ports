# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	trafficserver
PORTVERSION=	8.0.2
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Fast, scalable and extensible HTTP proxy server

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhwloc.so:devel/hwloc \
		libluajit-5.1.so:lang/luajit \
		libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2 \
		libbrotlienc.so:archivers/brotli

USES=		compiler:c++17-lang cpe gmake libtool ncurses pathfix \
		perl5 pkgconfig sqlite ssl tar:bzip2 tcl

CPE_VENDOR=	apache
CPE_PRODUCT=	traffic_server
USE_GCC=	7+
USE_PERL5=	build run
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" PORTVERSION="${PORTVERSION}"

LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libxml2=${LOCALBASE} \
		--with-pcre=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--with-xml=libxml2 \
		--with-tcl=${TCL_LIBDIR} \
		--localstatedir=/var \
		--with-user=${USERS} \
		--with-group=${GROUPS} \
		--disable-maintainer-mode \
		--disable-dependency-tracking \
		--enable-mime-sanity-check \
		--enable-experimental-plugins

OPTIONS_DEFINE=	DOCS WCCP MEMCACHED IMAGEMAGICK X11
OPTIONS_SUB=	yes

WCCP_DESC=	Enable WCCPv2 protocol
WCCP_CONFIGURE_ENABLE=	wccp

MEMCACHED_DESC=		Enable memcache & memcached_remap plugin

IMAGEMAGICK_DESC=	Enable ats-magick & webp convert plugin

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=	libmemcached.so:databases/libmemcached
PLIST_SUB+=	MEMCACHED=""
.else
PLIST_SUB+=	MEMCACHED="@comment "
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6
.else
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:graphics/ImageMagick6-nox11
.endif
PLIST_SUB+=	IMAGEMAGICK=""
.else
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MWCCP}
PLIST_SUB+=	WCCP=""
.else
PLIST_SUB+=	WCCP="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/cachedir:/s,$${localstatedir}+,$${localstatedir}/cache+,' \
		-e '/runtimedir:/s,$${localstatedir}+,$${localstatedir}/run+,' \
		${WRKSRC}/config.layout
	@${REINPLACE_CMD} '/^LUA_LDFLAGS =/s/$$/ @LDFLAGS@/' \
		${WRKSRC}/lib/Makefile.in


post-install:
	${RMDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/snapshots
	(cd ${STAGEDIR}${ETCDIR} && for f in *.config *.yaml; do ${MV} $$f $$f.sample; done)
	${SED} -i '' -e 's|^${STAGEDIR}||g' \
		${STAGEDIR}${PREFIX}/lib/perl5/amd64-freebsd-thread-multi/auto/Apache/TS/.packlist

.include <bsd.port.post.mk>
