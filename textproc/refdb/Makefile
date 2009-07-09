# New ports collection makefile for:   refdb
# Date created:	28 Apr 2005
# Whom:		paulh@logicsquad.net
#
# $FreeBSD$
#

PORTNAME=	refdb
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SFE
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Bibliographic reference database

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		btparse.0:${PORTSDIR}/textproc/btparse \
		dbi.0:${PORTSDIR}/databases/libdbi

USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	5.6.0+
HAS_CONFIGURE=	yes
ALL_TARGET=

CFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ARGS+=	--with-expat-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-classpath-root=${PREFIX}/share/java/classes
CONFIGURE_ARGS+=	--with-refdb-url=http://localhost/refdb
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}-1

XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

OPTIONS=	MYSQL	"Use MySQL" on \
		PGSQL	"Use PostgreSQL" off \
		SQLITE	"Use SQLite" off \
		CATALOG	"Install SGML catalog" off

MAN1=	bib2ris.1 bib2ris-utf8.1 db2ris.1 eenc.1 en2ris.1 marc2ris.1 med2ris.1 \
	refdb-backup.1 refdb-bug.1 refdb-ms.1 refdb-restore.1 \
	refdb_dos2unix.1 refdb_latex2utf8txt.1 refdba.1 \
	refdbc.1 refdbctl.1 refdbd.1 refdbib.1 refdbjade.1 \
	refdbnd.1 refdbxml.1 refdbxp.1 runbib.1 \
	refdb-sruserver.1 refdbsru.1
#MAN7=	RefDB.7
MAN8=	refdb.8 refdb.sh.8 refdb-init.8

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE)
IGNORE=		you must choose a back-end database
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
# If libdbi-drivers has been built without MySQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdmysql.so)
IGNORE=		rebuild databases/libdbi-drivers with MySQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=mysql

.elif defined(WITH_PGSQL)
USE_PGSQL=	yes
# If libdbi-drivers has been built without PostgreSQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdpgsql.so)
IGNORE=		rebuild databases/libdbi-drivers with PostgreSQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=pgsql

.elif defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
# If libdbi-drivers has been built without SQLite driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdsqlite.so)
IGNORE=		rebuild databases/libdbi-drivers with SQLite support
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
	@${ECHO_MSG} "1. To initialise MySQL, run the following command:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   mysql -u root -e \"CREATE DATABASE refdb\""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   Then, for MySQL older than 4.1, run:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   mysql -u root refdb < ${PREFIX}/share/refdb/sql/refdb.dump.mysql"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   For MySQL 4.1 and later, run:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   mysql -u root refdb < ${PREFIX}/share/refdb/sql/refdb.dump.mysql41"
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
	@${ECHO_MSG} "   http://refdb.sourceforge.net/manual/x593.html#SECT1-MYSTERY-INIT-FILES"

.include <bsd.port.post.mk>
