# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	perdition
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	mail net security
MASTER_SITES=	http://horms.net/projects/perdition/download/${PORTVERSION}/

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	POP3 & IMAP4 proxy that can map users to multiple backend servers

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		vanessa_logger:${PORTSDIR}/devel/libvanessa_logger \
		vanessa_socket:${PORTSDIR}/devel/libvanessa_socket \
		vanessa_adt:${PORTSDIR}/devel/libvanessa_adt

MAN5=		perditiondb.5
MAN8=		perdition.8
MLINKS=		perdition.8 perdition.imap4.8 \
		perdition.8 perdition.imap4s.8 \
		perdition.8 perdition.imaps.8 \
		perdition.8 perdition.pop3.8 \
		perdition.8 perdition.pop3s.8
MANCOMPRESSED=	no

USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	DOCSDIR=${DOCSDIR}
CONFIGURE_ARGS+=--localstatedir=/var

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
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--disable-daemon-map
PLIST_SUB+=		DAEMONMAP="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
CPPFLAGS+=		-I${BDB_INCLUDE_DIR}
CONFIGURE_ARGS+=	--enable-bdb
PLIST_SUB+=		BDB=""
USE_BDB=		yes
MAN1+=			makebdb.1
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
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
PLIST_SUB+=		GDBM=""
MAN1+=			makegdbm.1
.else
CONFIGURE_ARGS+=	--disable-gdbm
PLIST_SUB+=		GDBM="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
MAN8+=			perditiondb_mysql_makedb.8
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--enable-pg
USE_PGSQL=		yes
PLIST_SUB+=		PGSQL=""
MAN8+=			perditiondb_postgresql_makedb.8
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
MAN8+=			perditiondb_ldap_makedb.8
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		odbc:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=		ODBC=""
MAN8+=			perditiondb_odbc_makedb.8
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
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/etc/pam.d/perdition ${DOCSDIR}/perdition-pam.sample
	@${ECHO_MSG} ""
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} " If you want to use PAM with perdition, have a look at :"
	@${ECHO_MSG} " ${DOCSDIR}/perdition-pam.sample"
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
