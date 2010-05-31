# New ports collection makefile for:	perdition
# Date created:				28 April 2001
# Whom:					Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	perdition
PORTVERSION=	1.17.1
PORTREVISION=	4
CATEGORIES=	mail net security
MASTER_SITES=	http://www.vergenet.net/linux/perdition/download/${PORTVERSION}/

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	A POP3 & IMAP4 proxy that can map users to multiple backend servers

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		vanessa_socket.0:${PORTSDIR}/devel/libvanessa_socket \
		vanessa_adt.0:${PORTSDIR}/devel/libvanessa_adt

MAN5=		perditiondb.5
MAN8=		perdition.8

MANCOMPRESSED=	no

USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" BDB_LIB=db3
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	DOCSDIR=${DOCSDIR}
CONFIGURE_ARGS+=--disable-daemon-map --localstatedir=/var

USE_LDCONFIG=	yes
USE_RC_SUBR=	perdition perdition.pop3 perdition.pop3s \
		perdition.imap4 perdition.imap4s perdition.imaps

##
## Available knobs:
##   WITH_BDB: Enable Berkerley database backend
##   WITH_DAEMON_MAP: Enable Daemon Map support
##   WITH_GDBM: Enable gdbm database backend
##   WITH_MYSQL: Enable MySQL database backend
##   WITH_NIS: Enable NIS database backend
##   WITH_PGSQL: Enable PostgreSQL database backend
##   WITH_ODBC: Enable ODBC database backend
##   WITH_OPENLDAP: Enable OpenLDAP database backend
##
##   WITHOUT_SSL: Disable OpenSSL support
##   WITHOUT_POSIX_REGEX: Disable native regex support
##

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=		yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !defined(WITHOUT_POSIX_REGEX)
CONFIGURE_ARGS+=	--enable-posix_regex
PLIST_SUB+=		POSIXREGEX=""
.else
CONFIGURE_ARGS+=	--disable-posix_regex
PLIST_SUB+=		POSIXREGEX="@comment "
.endif

.if defined(WITH_DAEMON_MAP)
CONFIGURE_ARGS+=	--enable-daemon-map
PLIST_SUB+=		DAEMONMAP=""
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--disable-daemon-map
PLIST_SUB+=		DAEMONMAP="@comment "
.endif

.if defined(WITH_BDB)
CONFIGURE_ARGS+=	--enable-bdb
PLIST_SUB+=		BDB=""
LIB_DEPENDS+=		db3.3:${PORTSDIR}/databases/db3
MAN1+=			makebdb.1
.else
CONFIGURE_ARGS+=	--disable-bdb
PLIST_SUB+=		BDB="@comment "
.endif

.if defined(WITH_NIS)
CONFIGURE_ARGS+=	--enable-nis
PLIST_SUB+=		NIS=""
.else
CONFIGURE_ARGS+=	--disable-nis
PLIST_SUB+=		NIS="@comment "
.endif

.if defined(WITH_GDBM)
CONFIGURE_ARGS+=	--enable-gdbm
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=		GDBM=""
MAN1+=			makegdbm.1
.else
CONFIGURE_ARGS+=	--disable-gdbm
PLIST_SUB+=		GDBM="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
MAN8+=			perditiondb_mysql_makedb.8
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--enable-pg
USE_PGSQL=		yes
PLIST_SUB+=		PGSQL=""
MAN8+=			perditiondb_postgresql_makedb.8
.else
CONFIGURE_ARGS+=	--disable-pg
PLIST_SUB+=		PGSQL="@comment "
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--enable-ldap \
			--with-ldap-schema-directory=${LOCALBASE}/etc/openldap/schema/ \
			--disable-ldap-doc
PLIST_SUB+=		OPENLDAP=""
MAN8+=			perditiondb_ldap_makedb.8
.else
CONFIGURE_ARGS+=	--disable-ldap
PLIST_SUB+=		OPENLDAP="@comment "
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=	--enable-odbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB+=		ODBC=""
MAN8+=			perditiondb_odbc_makedb.8
.else
CONFIGURE_ARGS+=	--disable-odbc
PLIST_SUB+=		ODBC="@comment "
.endif

pre-everything:: show-options

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

post-install:
.if !defined(NOPORTDOCS)
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
