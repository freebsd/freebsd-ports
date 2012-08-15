# New ports collection makefile for:	c-icap
# Date created:				30 January 2006
# Whom:					Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	c-icap
PORTVERSION=	0.2.1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2.x/
DISTNAME=	c_icap-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	ICAP server implementation

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	c-icap

SUB_FILES=	pkg-install pkg-deinstall

OPTIONS_DEFINE=	BDB IPV6 LDAP PERL POSIXSEM LARGE_FILES
OPTIONS_DEFAULT=	IPV6
LARGE_FILES_DESC=	Enable large files support
POSIXSEM_DESC=		Use POSIX Semaphores instead of SYSV IPC

CICAP_USER=	c_icap
CICAP_GROUP=	c_icap

USERS=		${CICAP_USER}
GROUPS=		${CICAP_GROUP}

MAN8=		c-icap-client.8 \
		c-icap-config.8 \
		c-icap-libicapapi-config.8 \
		c-icap-mkbdb.8 \
		c-icap-stretch.8 \
		c-icap.8

CONFIGURE_ARGS+=	--enable-static

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
USE_PERL5=	yes
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
		${WRKSRC}/c-icap.conf.in
.if ${PORT_OPTIONS:MPOSIXSEM}
	@${REINPLACE_CMD} \
		-e 's|@SYSV_IPC@|0|g' \
		${WRKSRC}/include/c-icap-conf.h.in
.endif

post-install:
	@[ -f ${PREFIX}/etc/c-icap.conf ] || \
		${CP} -p ${PREFIX}/etc/c-icap.conf.default ${PREFIX}/etc/c-icap.conf
	@[ -f ${PREFIX}/etc/c-icap.magic ] || \
		${CP} -p ${PREFIX}/etc/c-icap.magic.default ${PREFIX}/etc/c-icap.magic
	@${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
