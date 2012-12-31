# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jabberd
PORTVERSION=	2.2.16
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://cloud.github.com/downloads/Jabberd2/jabberd2/
DIST_SUBDIR=	jabber

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		idn.17:${PORTSDIR}/dns/libidn \
		udns.0:${PORTSDIR}/dns/udns

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	MYSQL PGSQL LDAP BDB SQLITE FAM PIPE ANON FS DEBUG REQUIRES \
		CYRUS DOCS
OPTIONS_DEFAULT=	MYSQL DEBUG
PIPE_DESC=	Enable pipe (auth/reg)
ANON_DESC=	Enable anonymous (auth/reg)
FS_DESC=	Filesystem storage (only for testing)
REQUIRES_DESC=	Add backend requires to startup script
CYRUS_DESC=	Use Cyrus SASL backend (not supported)

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_PERL5_RUN=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_RC_SUBR=	jabberd
USE_LDCONFIG=	${PREFIX}/lib/jabberd
CONFIGURE_ARGS+=	--localstatedir=/var \
		--sysconfdir=${PREFIX}/etc/jabberd \
		--enable-ssl --enable-mio=poll \
		--disable-tests \
		--with-extra-include-path="${LOCALBASE}/include ${EIP}" \
		--with-extra-library-path="${LOCALBASE}/lib ${ELP}"

JABBER_USER=	jabber
JABBER_GROUP=	jabber

USERS=		${JABBER_USER}
GROUPS=		${JABBER_GROUP}

JABBER_ETCDIR=	"${PREFIX}/etc/jabberd"
JABBER_RUNDIR=	"/var/jabberd"

SUB_LIST+=	JABBER_USER=${JABBER_USER} \
		JABBER_GROUP=${JABBER_GROUP} \
		JABBER_ETCDIR="${JABBER_ETCDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}" \
		PERL="${PERL}"

SUB_FILES+=	pkg-install pkg-deinstall

PORTDOCS=	*

DOCFILES=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		TODO UPGRADE

_REQUIRE=	LOGIN

.include <bsd.port.options.mk>

ELP+=	${OPENSSLLIB}
EIP+=	${OPENSSLINC}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-pgsql
PLIST_SUB+=	SUB_PGSQL=""
_REQUIRE+=	postgresql
.else
CONFIGURE_ARGS+=--disable-pgsql
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=--enable-sqlite
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CFLAGS+=	${PTHREAD_CFLAGS}
PLIST_SUB+=	SUB_SQLITE=""
.else
CONFIGURE_ARGS+=--disable-sqlite
PLIST_SUB+=	SUB_SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
EIP+=:${LOCALBASE}/include/mysql
ELP+=:${LOCALBASE}/lib/mysql
PLIST_SUB+=	SUB_MYSQL=""
_REQUIRE+=	mysql
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	SUB_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	41+
CONFIGURE_ARGS+=--enable-db
CONFIGURE_ARGS+=--oldincludedir=/nonexistant
EIP+=:${BDB_INCLUDE_DIR}
ELP+=:${BDB_LIB_DIR}
PLIST_SUB+=	SUB_BDB=""
.else
CONFIGURE_ARGS+=--disable-db
PLIST_SUB+=	SUB_BDB="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-ldap
PLIST_SUB+=	SUB_LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MFS}
CONFIGURE_ARGS+=--enable-fs
PLIST_SUB+=	SUB_FS=""
.else
CONFIGURE_ARGS+=--disable-fs
PLIST_SUB+=	SUB_FS="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--enable-pam
PLIST_SUB+=	SUB_PAM=""
.else
CONFIGURE_ARGS+=--disable-pam
PLIST_SUB+=	SUB_PAM="@comment "
.endif

.if ${PORT_OPTIONS:MPIPE}
CONFIGURE_ARGS+=--enable-pipe
PLIST_SUB+=	SUB_PIPE=""
.else
PLIST_SUB+=	SUB_PIPE="@comment "
.endif

.if ${PORT_OPTIONS:MANON}
CONFIGURE_ARGS+=--enable-anon
PLIST_SUB+=	SUB_ANON=""
.else
PLIST_SUB+=	SUB_ANON="@comment "
.endif

.if ${PORT_OPTIONS:MREQUIRES}
SUB_LIST+=	REQUIRE="${_REQUIRE}"
.else
SUB_LIST+=	REQUIRE="LOGIN"
.endif

.if ${PORT_OPTIONS:MCYRUS}
CONFIGURE_ARGS+=	--with-sasl=cyrus
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
.else
CONFIGURE_ARGS+=	--with-sasl=gsasl
LIB_DEPENDS+=	gsasl.16:${PORTSDIR}/security/gsasl
.endif

MAN8=		c2s.8 jabberd.8 router.8 s2s.8 sm.8

post-patch:
	@${REINPLACE_CMD} -e 's|"-lsqlite3|"-lsqlite3 ${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|g' \
		${WRKSRC}/tools/jabberd.in
.if ${PORT_OPTIONS:MCYRUS}
	@${REINPLACE_CMD} -e '/^#error /d' \
		${WRKSRC}/sx/sasl_cyrus.c
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ${JABBER_USER}:${JABBER_GROUP} ${PREFIX}/etc/jabberd
	@${FIND} ${PREFIX}/etc/jabberd -type d | ${XARGS} ${CHMOD} 750
	@${FIND} ${PREFIX}/etc/jabberd -type f | ${XARGS} ${CHMOD} 660
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in db-setup.mysql db-setup.pgsql db-setup.sqlite
	@${INSTALL_DATA} ${WRKSRC}/tools/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
