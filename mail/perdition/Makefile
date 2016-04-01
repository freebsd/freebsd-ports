# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	perdition
PORTVERSION=	2.1
CATEGORIES=	mail net security
MASTER_SITES=	http://horms.net/projects/perdition/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 & IMAP4 proxy that can map users to multiple backend servers

LIB_DEPENDS=	libpopt.so:devel/popt \
		libvanessa_logger.so:devel/libvanessa_logger \
		libvanessa_socket.so:devel/libvanessa_socket \
		libvanessa_adt.so:devel/libvanessa_adt

USES=		gettext libtool pkgconfig shebangfix
SHEBANG_FILES=	${WRKSRC}/perdition/db/ldap/perditiondb_ldap_makedb \
		${WRKSRC}/perdition/db/mysql/perditiondb_mysql_makedb \
		${WRKSRC}/perdition/db/odbc/perditiondb_odbc_makedb \
		${WRKSRC}/perdition/db/postgresql/perditiondb_postgresql_makedb
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	DOCSDIR=${DOCSDIR}
CONFIGURE_ARGS+=--localstatedir=/var
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes
USE_RC_SUBR=	perdition perdition.pop3 perdition.pop3s \
		perdition.imap4 perdition.imap4s perdition.imaps

OPTIONS_DEFINE=		BDB DAEMON_MAP DOCS GDBM LDAP MYSQL NIS ODBC \
			OPENSSL PGSQL POSIX_REGEX
OPTIONS_DEFAULT=	GDBM OPENSSL POSIX_REGEX

DAEMON_MAP_DESC=	Daemon Map support
GDBM_DESC=		GDBM database
POSIX_REGEX_DESC=	Native regex support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=		yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MPOSIX_REGEX}
CONFIGURE_ARGS+=	--enable-posix_regex
PLIST_SUB+=		POSIXREGEX=""
.else
CONFIGURE_ARGS+=	--disable-posix_regex
PLIST_SUB+=		POSIXREGEX="@comment "
.endif

.if ${PORT_OPTIONS:MDAEMON_MAP}
CONFIGURE_ARGS+=	--enable-daemon-map
PLIST_SUB+=		DAEMONMAP=""
LIB_DEPENDS+=		libgdbm.so:databases/gdbm
.else
CONFIGURE_ARGS+=	--disable-daemon-map
PLIST_SUB+=		DAEMONMAP="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
CPPFLAGS+=		-I${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=	--enable-bdb
PLIST_SUB+=		BDB=""
USE_BDB=		yes
.else
CONFIGURE_ARGS+=	--disable-bdb
PLIST_SUB+=		BDB="@comment "
.endif

.if ${PORT_OPTIONS:MNIS}
CONFIGURE_ARGS+=	--enable-nis
PLIST_SUB+=		NIS=""
.else
CONFIGURE_ARGS+=	--disable-nis
PLIST_SUB+=		NIS="@comment "
.endif

.if ${PORT_OPTIONS:MGDBM}
CONFIGURE_ARGS+=	--enable-gdbm
LIB_DEPENDS+=		libgdbm.so:databases/gdbm
PLIST_SUB+=		GDBM=""
.else
CONFIGURE_ARGS+=	--disable-gdbm
PLIST_SUB+=		GDBM="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--enable-pg
USES+=			pgsql
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pg
PLIST_SUB+=		PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--enable-ldap \
			--with-ldap-schema-directory=${LOCALBASE}/etc/openldap/schema/ \
			--disable-ldap-doc
PLIST_SUB+=		LDAP=""
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		libodbc.so:databases/unixODBC
PLIST_SUB+=		ODBC=""
.else
CONFIGURE_ARGS+=	--disable-odbc
PLIST_SUB+=		ODBC="@comment "
.endif

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|g' \
		configure \
		makebdb/Makefile.in \
		perdition/db/bdb/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/etc/pam.d/perdition ${STAGEDIR}${DOCSDIR}/perdition-pam.sample
	@${ECHO_MSG} ""
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} " If you want to use PAM with perdition, have a look at :"
	@${ECHO_MSG} " ${DOCSDIR}/perdition-pam.sample"
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
