# New ports collection makefile for:   refdb
# Date created:	28 Apr 2005
# Whom:		paulh@logicsquad.net
#
# $FreeBSD$
#

PORTNAME=	refdb
PORTVERSION=	0.9.5a
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	paulh@logicsquad.net
COMMENT=	Bibliographic reference database

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/refdb-0.9.5
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=

CFLAGS+=	-I${LOCALBASE}/include
# Change these:
CONFIGURE_ARGS+=	--with-expat-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-classpath-root=${PREFIX}/share/java/classes
CONFIGURE_ARGS+=	--with-refdb-url=http://localhost/refdb

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

# For testing:
#CONFIGURE_ARGS+=	--prefix=/home/paulh/ports/textproc/refdb/install

OPTIONS=	MYSQL	"Use MySQL" on \
		PGSQL	"Use PostgreSQL" off \
		SQLITE	"Use SQLite" off \
		CATALOG	"Install SGML catalog" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE)
IGNORE=		You must choose a back-end database
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
# If libdbi-drivers has been built without MySQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libmysql.so)
IGNORE=		Rebuild databases/libdbi-drivers with MySQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=mysql

.elif defined(WITH_PGSQL)
USE_PGSQL=	yes
# If libdbi-drivers has been built without PostgreSQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libpgsql.so)
IGNORE=		Rebuild databases/libdbi-drivers with PostgreSQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=pgsql

.elif defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite2
# If libdbi-drivers has been built without SQLite driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libsqlite.so)
IGNORE=		Rebuild databases/libdbi-drivers with SQLite support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=sqlite
.endif

.if defined(WITH_CATALOG)
RUN_DEPENDS+=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr
.endif

post-install:
.if defined(WITH_CATALOG)
	@[ -f ${PREFIX}/share/sgml/catalog.ports ] || ${TOUCH} ${PREFIX}/share/sgml/catalog.ports
	@${XMLCATMGR} -s -c ${PREFIX}/share/sgml/catalog.ports lookup "${PREFIX}/share/refdb/refdb.cat" > /dev/null || ${XMLCATMGR} -s -c ${PREFIX}/share/sgml/catalog.ports add CATALOG "${PREFIX}/share/refdb/refdb.cat" -- > /dev/null
.endif
	@${ECHO_MSG} "To complete RefDB installation:"
.if defined(WITH_MYSQL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "1. To initialise MySQL, run the following commands:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   mysql -u root -e \"CREATE DATABASE refdb\""
	@${ECHO_MSG} "   mysql -u root refdb < ${PREFIX}/share/refdb/sql/refdb.dump"
	@${ECHO_MSG} ""
.elif defined(WITH_PGSQL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "1. To initialise PostgreSQL, run the following commands:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   createdb -U pgsql -E UNICODE refdb"
	@${ECHO_MSG} "   psql -U pgsql refdb < ${PREFIX}/share/refdb/sql/refdb.dump.pgsql"
	@${ECHO_MSG} ""
.elif defined(WITH_SQLITE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "1. To initialise SQLite, run the following commands:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   cd ${PREFIX}/share/refdb/db"
	@${ECHO_MSG} "   sqlite refdb < ${PREFIX}/share/refdb/sql/refdb.dump.sqlite"
	@${ECHO_MSG} ""
.endif
	@${INSTALL_SCRIPT} -m 755 ${WRKSRC}/scripts/refdb ${PREFIX}/etc/rc.d/refdb.sh.dist
	@${ECHO_MSG} "2. To run refdbd at system startup, rename the startup script:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   mv ${PREFIX}/etc/rc.d/refdb.sh.dist ${PREFIX}/etc/rc.d/refdb.sh"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "3. Customise the configuration scripts in ${PREFIX}/etc/refdb,"
	@${ECHO_MSG} "   as described in the RefDB documentation at:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   http://refdb.sourceforge.net/manual/x1390.html#AEN1484"

.include <bsd.port.post.mk>
