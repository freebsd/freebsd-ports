# New ports collection makefile for:	perdition
# Date created:				28 April 2001
# Whom:					Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	perdition
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	mail net security
MASTER_SITES=	http://www.vergenet.net/linux/perdition/download/${PORTVERSION}/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	A POP3 & IMAP4 proxy that can map users to multiple backend servers

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		popt.0:${PORTSDIR}/devel/popt \
		vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		vanessa_socket.0:${PORTSDIR}/devel/libvanessa_socket \
		vanessa_adt.0:${PORTSDIR}/devel/libvanessa_adt

MAN5=		perditiondb.5
MAN8=		perdition.8
MLINK=		perdition.8  - perdition.pop3s.8 \
		-  perdition.imap4.8 -  perdition.imap4s.8 \
		- perdition.imaps.8  - perdition.pop3.8

MANCOMPRESSED=	no

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV+=	DOCSDIR=${DOCSDIR}

INSTALLS_SHLIB=	yes

# Available knobs:
# WITHOUT_SSL: Disable OpenSSL support
# WITHOUT_POSIX_REGEX: Disable native regex support
# WITH_BDB: Enable Berkerley database backend
# WITH_NIS: Enable NIS database backend
# WITH_GDBM: Enable gdbm database backend
# WITH_MYSQL: Enable MySQL database backend
# WITH_MYSQL_VER:
#		- 323 use MySQL 3.23.x
#		- 40 use MySQL 4.0.x
#		- 41 use MySQL 4.1.x
# WITH_PGSQL: Enable PostgreSQL database backend
# WITH_OPENLDAP: Enable OpenLDAP database backend
# WITH_ODBC: Enable ODBC database backend

LDAP_VER?=	21

# MySQL deps hack (revision 2)
MYSQL323_LIBVER=10
MYSQL40_LIBVER=	12
MYSQL41_LIBVER=	14

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL_VER)
MYSQL_VER=	${WITH_MYSQL_VER}
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL_323_LIBVER})
MYSQL_VER=	323
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL40_LIBVER})
MYSQL_VER=	40
.elif exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.${MYSQL41_LIBVER})
MYSQL_VER=	41
.else
MYSQL_VER=	40
.endif

.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=		yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if !defined(WITHOUT_POSIX_REGEX)
CONFIGURE_ARGS+=	--enable-posix_regex
PLIST_SUB+=		POSIX_REGEX=""
.else
CONFIGURE_ARGS+=	--disable-posix_regex
PLIST_SUB+=		POSIX_REGEX="@comment "
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
CONFIGURE_ARGS+=	--enable-mysql
LIB_DEPENDS+=		mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
PLIST_SUB+=		MYSQL=""
MAN8+=			perditiondb_mysql_makedb.8
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--enable-pg
LIB_DEPENDS+=		pq:${PORTSDIR}/databases/postgresql7
PLIST_SUB+=		PGSQL=""
MAN8+=			perditiondb_postgresql_makedb.8
.else
CONFIGURE_ARGS+=	--disable-pg
PLIST_SUB+=		PGSQL="@comment "
.endif

.if defined(WITH_OPENLDAP)
CONFIGURE_ARGS+=	--enable-ldap --with-ldap-schema-directory=${LOCALBASE}/etc/openldap/schema/
LIB_DEPENDS+=		ldap.2:${PORTSDIR}/net/openldap${LDAP_VER}
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

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/etc/pam.d/perdition ${DOCSDIR}/perdition-pam.sample
	@${ECHO_MSG} ""
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} " If you want to use PAM with perdition, have a look at :"
	@${ECHO_MSG} " ${DOCSDIR}/perdition-pam.sample"
	@${ECHO_MSG} "/********************************************************/"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
