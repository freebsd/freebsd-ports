# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	c-icap
PORTVERSION=	0.3.3
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.3.x/
DISTNAME=	c_icap-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	ICAP server implementation

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	c-icap

SUB_FILES=	pkg-install pkg-deinstall

OPTIONS_DEFINE=	BDB IPV6 LDAP PERL POSIXSEM LARGE_FILES
OPTIONS_DEFAULT=	IPV6
LARGE_FILES_DESC=	Enable large files support
POSIXSEM_DESC=		Use POSIX Semaphores instead of SYSV IPC

CICAP_USER=	c_icap
CICAP_UID=	959
CICAP_GROUP=	c_icap
CICAP_GID=	959

USERS=		${CICAP_USER}
GROUPS=		${CICAP_GROUP}

MAN8=		c-icap-client.8 \
		c-icap-config.8 \
		c-icap-libicapapi-config.8 \
		c-icap-mkbdb.8 \
		c-icap-stretch.8 \
		c-icap.8

CONFIGURE_ARGS+=	--enable-static \
			--sysconfdir="${PREFIX}/etc/c-icap" \
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

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
.endif

.include <bsd.port.pre.mk>

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
PLIST_SUB+=	LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	CICAP_USER=${CICAP_USER} CICAP_GROUP=${CICAP_GROUP} \
		LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|@prefix@/var/log|/var/log/c-icap|g' \
		-e 's|@prefix@/etc/|@sysconfdir@/|g' \
		${WRKSRC}/c-icap.conf.in
.if ${PORT_OPTIONS:MPOSIXSEM}
	@${REINPLACE_CMD} \
		-e 's|@SYSV_IPC@|0|g' \
		${WRKSRC}/include/c-icap-conf.h.in
.endif

post-install:
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/c-icap.conf.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/c-icap.conf || ${TRUE}
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/c-icap.magic.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/c-icap.magic || ${TRUE}

.include <bsd.port.post.mk>
