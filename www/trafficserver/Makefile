# Created by: Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	trafficserver
PORTVERSION=	4.1.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	APACHE/${PORTNAME}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	Fast, scalable and extensible HTTP proxy server

LICENSE=	APACHE20

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libluajit-${LUA_VER}.so:${PORTSDIR}/lang/luajit

USE_AUTOTOOLS=	autoconf automake libtool aclocal
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		pkgconfig tcl gmake perl5
USE_OPENSSL=	yes
USE_SQLITE=	yes
USE_RC_SUBR=	${PORTNAME}
USE_LUA=	5.1+
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
USERS=		www
GROUPS=		nogroup

LOGDIR=		/var/log/${PORTNAME}

PLIST_SUB=	LOGDIR="${LOGDIR}"

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-libxml2=${LOCALBASE} \
		--with-pcre=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--with-xml=libxml2 \
		--with-lua=${LOCALBASE} --enable-luajit \
		--with-tcl=${TCL_LIBDIR} \
		--verbose \
		--enable-cppapi \
		--with-user=${USERS} \
		--with-group=${GROUPS}

ACLOCAL_ARGS=	-I build
OPTIONS_DEFINE=	WCCP INTERIM
OPTIONS_RADIO=	MEMMAN
OPTIONS_RADIO_MEMMAN=	ALLOCATORS FREELISTS RECLAIM
OPTIONS_DEFAULT=	FREELISTS

WCCP_DESC=	Enable WCCPv2 protocol
INTERIM_DESC=	Enable interim cache (SSD)
ALLOCATORS_DESC=	Manage memory with allocators
FREELISTS_DESC=	Manage memory with freelists
RECLAIM_DESC=	Reclaim unused memory in freelists

WCCP_CONFIGURE_ENABLE=	wccp
INTERIM_CONFIGURE_ENABLE=	interim-cache

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRECLAIM}
CONFIGURE_ARGS+=	--enable-reclaimable-freelist --enable-freelist
.elif ${PORT_OPTIONS:MFREELISTS}
CONFIGURE_ARGS+=	--enable-freelist
.elif ${PORT_OPTIONS:MALLOCATORS}
CONFIGURE_ARGS+=	--disable-freelist
.else
FORBIDDEN=	No allocation strategy selected
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/snapshots
	@cd ${STAGEDIR}${ETCDIR} && for f in *.config *.config.xml; do ${MV} $$f $$f.default; done

.include <bsd.port.mk>
