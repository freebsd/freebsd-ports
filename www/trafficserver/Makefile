# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	trafficserver
PORTVERSION=	6.2.0
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Fast, scalable and extensible HTTP proxy server

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhwloc.so:devel/hwloc \
		libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe execinfo gmake libtool ncurses pathfix perl5 pkgconfig \
		sqlite ssl tar:bzip2 tcl
CPE_VENDOR=	apache
CPE_PRODUCT=	traffic_server
USE_PERL5=	build run
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

ONLY_FOR_ARCHS=	amd64

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" PORTVERSION="${PORTVERSION}"

LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libxml2=${LOCALBASE} \
		--with-pcre=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--with-xml=libxml2 \
		--with-tcl=${TCL_LIBDIR} \
		--enable-cppapi \
		--localstatedir=/var \
		--with-user=${USERS} \
		--with-group=${GROUPS}

OPTIONS_DEFINE=	DOCS WCCP SPDY

WCCP_DESC=	Enable WCCPv2 protocol
SPDY_DESC=	Enable SPDY

WCCP_CONFIGURE_ENABLE=	wccp
SPDY_CONFIGURE_ENABLE=	spdy
SPDY_LIB_DEPENDS=	libspdylay.so:www/spdylay

.if ! exists(/var/cache)
# FreeBSD 8.x
PLIST_DIRS+=	/var/cache
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/cachedir:/s,$${localstatedir}+,$${localstatedir}/cache+,' \
		-e '/runtimedir:/s,$${localstatedir}+,$${localstatedir}/run+,' \
		${WRKSRC}/config.layout
	@${REINPLACE_CMD} '/^LUA_LDFLAGS =/s/$$/ @LDFLAGS@/' \
		${WRKSRC}/lib/Makefile.in

post-install:
	@${RMDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/snapshots
	(cd ${STAGEDIR}${ETCDIR} && for f in *.config *.config.xml; do ${MV} $$f $$f.sample; done)

.include <bsd.port.mk>
