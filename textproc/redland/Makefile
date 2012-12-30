# Created by: ijliao
# $FreeBSD$

PORTNAME=	redland
PORTVERSION=	1.0.16
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level interface for RDF

LIB_DEPENDS=	raptor2:${PORTSDIR}/textproc/raptor2 \
		rasqal:${PORTSDIR}/textproc/rasqal

USE_AUTOTOOLS=	libltdl
USE_GNOME=	gnomehack libxml2 lthack
USE_OPENSSL=	yes
USE_PERL5_BUILD=	yes
USE_PKGCONFIG=	both
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-raptor=system \
		--with-threestore=no
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		rdfproc.1 redland-config.1 \
		redland-db-upgrade.1
MAN3=		redland.3

OPTIONS_DEFINE=	BDB THREADS
OPTIONS_DEFAULT=	BDB
#		MYSQL "Use MySQL instead of BDB" off \
#		PGSQL "Use PgSQL instead of BDB" off \
#		SQLITE "Use SQLite instead of BDB" off \
#		VIRTUOSO "Use Virtoso instead of BDB" off

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
WITH_BDB_HIGHEST=	yes
INVALID_BDB_VER=	2
.else
CONFIGURE_ARGS+=	--with-bdb=no
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

#.if defined(WITH_MYSQL)
#USE_MYSQL=	yes
#CONFIGURE_ARGS+=--with-mysql=yes
#CONFIGURE_ENV+=	LIBS="${LIBS}"
#CFLAGS+=	-I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
#LDFLAGS+=	-L${LOCALBASE}/lib/mysql
#PLIST_SUB+=	MYSQL=""
#.else
CONFIGURE_ARGS+=--with-mysql=no
PLIST_SUB+=	MYSQL="@comment "
#.endif

#.if defined(WITH_PGSQL)
#USE_PGSQL=	yes
#CONFIGURE_ARGS+=--with-postgresql=yes
#PLIST_SUB+=	PGSQL=""
#.else
CONFIGURE_ARGS+=--with-postgresql=no
PLIST_SUB+=	PGSQL="@comment "
#.endif

#.if defined(WITH_SQLITE)
#USE_SQLITE=	3
#CONFIGURE_ARGS+=--with-sqlite=3
#PLIST_SUB+=	SQLITE=""
#.else
CONFIGURE_ARGS+=--with-sqlite=no
PLIST_SUB+=	SQLITE="@comment "
#.endif

#.if defined(WITH_VIRTUOSO)
#CONFIGURE_ARGS+=--with-virtuoso=yes
#LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
#PLIST_SUB+=	VIRTUOSO=""
#.else
CONFIGURE_ARGS+=--with-virtuoso=no
PLIST_SUB+=	VIRTUOSO="@comment "
#.endif

pre-everything::
.	if ${PORT_OPTIONS:MBDB}
	@${ECHO_CMD} "You can choose BDB version by setting WITH_BDB_VER to one off:"
	@${ECHO_CMD} "3 40 41 42 43 44 3+ 40+ 41+ 42+ 43+ 44+ (current: ${BDB_VER})"
.	endif
.	if defined(WITH_MYSQL)
	@${ECHO_CMD} "MySQL version to be used: ${MYSQL_VER}"
	@${ECHO_CMD} "If you don't have MySQL installed you can stop the build now"
	@${ECHO_CMD} "and set WITH_MYSQL_VER to the desired version"
.	endif

.include <bsd.port.mk>
