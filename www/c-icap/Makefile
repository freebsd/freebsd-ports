# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	c-icap
PORTVERSION=	0.5.6
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.5.x/
DISTNAME=	c_icap-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	ICAP server implementation

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libpcre.so:devel/pcre

USES=		cpe libtool localbase

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir="${PREFIX}/etc/c-icap" \
		--localstatedir=/var
INSTALL_TARGET=	install-strip
CPE_VENDOR=	c-icap_project
USE_LDCONFIG=	yes
USE_RC_SUBR=	c-icap

USERS=		${CICAP_USER}
GROUPS=		${CICAP_GROUP}

CICAP_USER=	c_icap
CICAP_UID=	959
CICAP_GROUP=	c_icap
CICAP_GID=	959

LOG_DIR=	/var/log/c-icap
RUN_DIR=	/var/run/c-icap
PLIST_SUB=	LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR} \
		CICAP_USER=${CICAP_USER} CICAP_GROUP=${CICAP_GROUP}
SUB_LIST=	RUN_DIR=${RUN_DIR} CICAP_USER=${CICAP_USER}

OPTIONS_DEFINE=		BDB IPV6 LDAP PERL POSIXSEM LARGE_FILES MEMCACHE
OPTIONS_SUB=		yes
LARGE_FILES_DESC=	Enable large files support
POSIXSEM_DESC=		Use POSIX Semaphores instead of SYSV IPC
MEMCACHE_DESC=		Enable memcached

IPV6_CONFIGURE_ENABLE=	ipv6

LARGE_FILES_CONFIGURE_ENABLE=	large-files

MEMCACHE_CONFIGURE_WITH=	memcached
MEMCACHE_LIB_DEPENDS=		libmemcached.so:databases/libmemcached

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=yes
LDAP_CONFIGURE_OFF=	--with-ldap=no

PERL_USES=		perl5
PERL_CONFIGURE_ON=	--with-perl=${PERL}
PERL_CONFIGURE_OFF=	--without-perl

BDB_USES=		bdb
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
BDB_CONFIGURE_ON=	--with-bdb=yes
BDB_CONFIGURE_OFF=	--with-bdb=no

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

.include <bsd.port.mk>
