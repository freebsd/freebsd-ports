# Created by: paulh@logicsquad.net
# $FreeBSD$

PORTNAME=	refdb
PORTVERSION=	0.9.9
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-src-${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	ohartman@zedat.fu-berlin.de
COMMENT=	Bibliographic reference database

BROKEN=		Fails to link

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libbtparse.so:${PORTSDIR}/textproc/btparse \
		libdbi.so:${PORTSDIR}/databases/libdbi

USES=		gmake iconv readline perl5 libtool pkgconfig pathfix shebangfix
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

CFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ARGS=	--with-expat-lib=${LOCALBASE}/lib \
		--with-classpath-root=${PREFIX}/share/java/classes \
		--with-refdb-url=http://localhost/refdb
XMLCATMGR=	${LOCALBASE}/bin/xmlcatmgr

OPTIONS_DEFINE=		DOCS CATALOG
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_EXCLUDE=	CATALOG 	# may not be implemented correctly
CATALOG_DESC=		Install SGML catalog

OPTIONS_DEFAULT=	PGSQL
DOCS_BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
			docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl

SHEBANG_FILES=          ${WRKSRC}/scripts/*

USE_RC_SUBR=            refdbd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USES+=  mysql
# If libdbi-drivers has been built without MySQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdmysql.so)
IGNORE=		rebuild databases/libdbi-drivers with MySQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=mysql

.elif ${PORT_OPTIONS:MPGSQL}
USES+=  pgsql
# If libdbi-drivers has been built without PostgreSQL driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdpgsql.so)
IGNORE=		rebuild databases/libdbi-drivers with PostgreSQL support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=pgsql

.elif ${PORT_OPTIONS:MSQLITE}
LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
# If libdbi-drivers has been built without SQLite driver, abort
.if exists(${LOCALBASE}/lib/dbd) && !exists(${LOCALBASE}/lib/dbd/libdbdsqlite3.so)
IGNORE=		rebuild databases/libdbi-drivers with SQLite support
.elif !exists(${LOCALBASE}/lib/dbd)
BUILD_DEPENDS+=	${LOCALBASE}/lib/dbd:${PORTSDIR}/databases/libdbi-drivers
.endif
CONFIGURE_ARGS+=	--with-db-server=sqlite
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-docbook-xsl=${PREFIX}/share/xsl/docbook \
			--without-docbook-xsl-ns \
			--without-tei-xsl \
			--without-tei-xsl-ns
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MCATALOG}
RUN_DEPENDS+=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$$(PACKAGE)-$$(VERSION)|refdb|g' \
		${WRKSRC}/doc/Makefile.in

post-install:
.if ${PORT_OPTIONS:MCATALOG}
	@[ -f ${STAGEDIR}${PREFIX}/share/sgml/catalog.ports ] || ${TOUCH} ${STAGEDIR}${PREFIX}/share/sgml/catalog.ports
	@${XMLCATMGR} -s -c ${STAGEDIR}${PREFIX}/share/sgml/catalog.ports lookup "${STAGEDIR}${PREFIX}/share/refdb/refdb.cat" > /dev/null || ${XMLCATMGR} -s -c ${STAGEDIR}${PREFIX}/share/sgml/catalog.ports add CATALOG "${STAGEDIR}${PREFIX}/share/refdb/refdb.cat" -- > /dev/null
.endif
	@${ECHO_MSG} "To complete RefDB installation:"
.if ${PORT_OPTIONS:MMYSQL}
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
.elif ${PORT_OPTIONS:MPGSQL}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "1. To initialise PostgreSQL, run the following commands:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   createdb -U pgsql -E UNICODE refdb"
	@${ECHO_MSG} "   psql -U pgsql refdb < ${PREFIX}/share/refdb/sql/refdb.dump.pgsql"
	@${ECHO_MSG} ""
.elif ${PORT_OPTIONS:MSQLITE}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "1. To initialise SQLite, run the following commands:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "   cd ${PREFIX}/share/refdb/db"
	@${ECHO_MSG} "   sqlite refdb < ${PREFIX}/share/refdb/sql/refdb.dump.sqlite"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
