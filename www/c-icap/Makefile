PORTNAME=	c-icap
PORTVERSION=	0.6.4
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.6.x/
DISTNAME=	c_icap-${PORTVERSION}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-server/commit/
PATCHFILES+=	aa28041.patch:-p1 # https://github.com/c-icap/c-icap-server/pull/67

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	ICAP server implementation
WWW=		https://c-icap.sourceforge.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libpcre.so:devel/pcre

USES=		cpe libtool localbase
CPE_VENDOR=	c-icap_project
USE_LDCONFIG=	yes
USE_RC_SUBR=	c-icap

GNU_CONFIGURE=			yes
CONFIGURE_ARGS=			--localstatedir=/var \
				--sysconfdir="${PREFIX}/etc/c-icap"
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip

SUB_LIST=	CICAP_USER=${CICAP_USER} \
		RUN_DIR=${RUN_DIR}

CICAP_USER=	c_icap
CICAP_UID=	959
CICAP_GROUP=	c_icap
CICAP_GID=	959
LOG_DIR=	/var/log/c-icap
RUN_DIR=	/var/run/c-icap
USERS=		${CICAP_USER}
GROUPS=		${CICAP_GROUP}

PLIST_SUB=	CICAP_GROUP=${CICAP_GROUP} \
		CICAP_USER=${CICAP_USER} \
		LOG_DIR=${LOG_DIR} \
		RUN_DIR=${RUN_DIR}

OPTIONS_DEFINE=		BDB IPV6 LARGE_FILES LDAP MEMCACHE PERL POSIXSEM
OPTIONS_SUB=		yes
LARGE_FILES_DESC=	Enable large files support
MEMCACHE_DESC=		Enable memcached
POSIXSEM_DESC=		Use POSIX Semaphores instead of SYSV IPC

BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb=yes
BDB_CONFIGURE_OFF=	--with-bdb=no
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}

IPV6_CONFIGURE_ENABLE=	ipv6

LARGE_FILES_CONFIGURE_ENABLE=	large-files

LDAP_USES=			ldap
LDAP_CONFIGURE_ON=		--with-ldap=yes
LDAP_CONFIGURE_OFF=		--with-ldap=no
MEMCACHE_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHE_CONFIGURE_WITH=	memcached

PERL_USES=		perl5
PERL_CONFIGURE_ON=	--with-perl=${PERL}
PERL_CONFIGURE_OFF=	--without-perl

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|@prefix@/var/log|/var/log/c-icap|g' \
		-e 's|@prefix@/etc/|@sysconfdir@/|g' \
		${WRKSRC}/c-icap.conf.in
	@${REINPLACE_CMD} \
		-e 's|\.default|.sample|g' \
		${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

post-patch-POSIXSEM-on:
	@${REINPLACE_CMD} \
		-e 's|@SYSV_IPC@|0|g' \
		${WRKSRC}/include/c-icap-conf.h.in

post-install:
	@${MKDIR} ${STAGEDIR}/${LOG_DIR} ${STAGEDIR}/${RUN_DIR}

.include <bsd.port.post.mk>
