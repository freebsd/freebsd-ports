# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=		prelude.0:${PORTSDIR}/security/libprelude \
			xml2.5:${PORTSDIR}/textproc/libxml2

GNU_MAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc \
			--program-prefix="" --localstatedir=/var

# MySQL deps hack
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

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--enable-openssl
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=		mysqlclient.${MYSQL${MYSQL_VER}_LIBVER}:${PORTSDIR}/databases/mysql${MYSQL_VER}-client
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_POSTGRES)
LIB_DEPENDS+=		pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=	--enable-pgsql
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		PGSQL="@comment "
.endif

post-patch:
	@${ECHO} ""
	@${ECHO} "*---------------------------------------------------------------------------*"
	@${ECHO} "Options:"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL=yes         Disable SSL support"
	@${ECHO} "      WITH_MYSQL=yes          Enable MySQL support"
	@${ECHO} "             - WITH_MYSQL_VER=323   Enable MySQL 3.23 support"
	@${ECHO} "             - WITH_MYSQL_VER=40    Enable MySQL 4.0 support (default)"
	@${ECHO} "             - WITH_MYSQL_VER=41    Enable MySQL 4.1 support"
	@${ECHO} "      WITH_POSTGRES=yes       Enable PostreSQL support"
	@${ECHO} "*---------------------------------------------------------------------------*"
	@${ECHO} ""

.include <bsd.port.post.mk>
