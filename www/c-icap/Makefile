# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	c-icap
PORTVERSION=	0.4.3
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.4.x/
DISTNAME=	c_icap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICAP server implementation

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe libtool
CPE_VENDOR=	c-icap_project
USE_LDCONFIG=	yes
USE_RC_SUBR=	c-icap

OPTIONS_DEFINE=	BDB IPV6 LDAP PERL POSIXSEM LARGE_FILES MEMCACHE
OPTIONS_DEFAULT=	IPV6
LARGE_FILES_DESC=	Enable large files support
POSIXSEM_DESC=		Use POSIX Semaphores instead of SYSV IPC
MEMCACHE_DESC=		Enable memcached

CICAP_USER=	c_icap
CICAP_UID=	959
CICAP_GROUP=	c_icap
CICAP_GID=	959

USERS=		${CICAP_USER}
GROUPS=		${CICAP_GROUP}

CONFIGURE_ARGS+=	--sysconfdir="${PREFIX}/etc/c-icap" \
			--localstatedir=/var

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MLARGE_FILES}
CONFIGURE_ARGS+=	--enable-large-files
.else
CONFIGURE_ARGS+=	--disable-large-files
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
CONFIGURE_ARGS+=	--with-memcached
BUILD_DEPENDS=		memcached:databases/memcached
PLIST_SUB+=		MEMCACHE=""
.else
CONFIGURE_ARGS+=	--without-memcached
PLIST_SUB+=		MEMCACHE="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MBDB}
CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=	--with-bdb=yes
PLIST_SUB+=	BDB=""
.else
CONFIGURE_ARGS+=	--with-bdb=no
PLIST_SUB+=	BDB="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap=yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=	--with-ldap=no
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
PLIST_SUB+=	PERL=""
CONFIGURE_ARGS+=	--with-perl=${PERL}
.else
PLIST_SUB+=	PERL="@comment "
CONFIGURE_ARGS+=	--without-perl
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LOG_DIR=	/var/log/c-icap
RUN_DIR=	/var/run/c-icap
PLIST_SUB+=	LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR} \
		CICAP_USER=${CICAP_USER} CICAP_GROUP=${CICAP_GROUP}
SUB_LIST+=	RUN_DIR=${RUN_DIR} CICAP_USER=${CICAP_USER}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|@prefix@/var/log|/var/log/c-icap|g' \
		-e 's|@prefix@/etc/|@sysconfdir@/|g' \
		${WRKSRC}/c-icap.conf.in
	@${REINPLACE_CMD} \
		-e 's|\.default|.sample|g' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.if ${PORT_OPTIONS:MPOSIXSEM}
	@${REINPLACE_CMD} \
		-e 's|@SYSV_IPC@|0|g' \
		${WRKSRC}/include/c-icap-conf.h.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}/${LOG_DIR} ${STAGEDIR}/${RUN_DIR}

.include <bsd.port.mk>
