# Created by: ijliao
# $FreeBSD$

PORTNAME=	redland
PORTVERSION=	1.0.17
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level interface for RDF

# Even though GPLv3 is not explicitly mentioned in the port's LICENSE.html, one
# of its licenses is "GPLv2 or newer", which includes GPLv3.
LICENSE=	APACHE20 GPLv2 GPLv3 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libraptor2.so:textproc/raptor2 \
		librasqal.so:textproc/rasqal

USE_PERL5=	build
USES=		gmake libtool pathfix perl5 pkgconfig shebangfix
SHEBANG_FILES=	scripts/touch-mtime.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-threestore=no
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	BDB THREADS
OPTIONS_DEFAULT=	BDB

BDB_USE=	BDB=yes
BDB_CONFIGURE_OFF=	--with-bdb=no

THREADS_CONFIGURE_ENABLE=	threads

#		MYSQL "Use MySQL instead of BDB" off \
#		PGSQL "Use PgSQL instead of BDB" off \
#		SQLITE "Use SQLite instead of BDB" off \
#		VIRTUOSO "Use Virtoso instead of BDB" off

#.if defined(WITH_MYSQL)
#USE_MYSQL=	yes
#CONFIGURE_ARGS+=--with-mysql=yes
#CPPFLAGS+=	-I${LOCALBASE}/include/mysql -DHAVE_MYSQL_H
#LIBS+=		-L${LOCALBASE}/lib/mysql
#PLIST_SUB+=	MYSQL=""
#.else
CONFIGURE_ARGS+=--with-mysql=no
PLIST_SUB+=	MYSQL="@comment "
#.endif

#.if defined(WITH_PGSQL)
#USES+=		pgsql
#CONFIGURE_ARGS+=--with-postgresql=yes
#PLIST_SUB+=	PGSQL=""
#.else
CONFIGURE_ARGS+=--with-postgresql=no
PLIST_SUB+=	PGSQL="@comment "
#.endif

#.if defined(WITH_SQLITE)
#USES+=		sqlite:3
#CONFIGURE_ARGS+=--with-sqlite=3
#PLIST_SUB+=	SQLITE=""
#.else
CONFIGURE_ARGS+=--with-sqlite=no
PLIST_SUB+=	SQLITE="@comment "
#.endif

#.if defined(WITH_VIRTUOSO)
#CONFIGURE_ARGS+=--with-virtuoso=yes
#LIB_DEPENDS+=	iodbc.3:databases/libiodbc
#PLIST_SUB+=	VIRTUOSO=""
#.else
CONFIGURE_ARGS+=--with-virtuoso=no
PLIST_SUB+=	VIRTUOSO="@comment "
#.endif

.include <bsd.port.mk>
