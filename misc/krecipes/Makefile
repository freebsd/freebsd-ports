# ports collection makefile for:	krecipies
# Date created:				19 March 2005
# Whom:					hank
#
# $FreeBSD$
#

PORTNAME=	krecipes
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	misc kde
MASTER_SITES=	SF

MAINTAINER=	hank@millerfarm.com
COMMENT=	Recipe database for cooks

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15

OPTIONS=	SQLITE "Support for SQLite backend" on \
		MYSQL "Support for MySQL backend" off \
		POSTGRESQL "Support for PostgreSQL backend" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SQLITE)
CONFIGURE_ARGS+=	--without-sqlite
.else
USE_SQLITE=	yes
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
.if defined(WITHOUT_SQLITE) && !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
	@${ECHO} "You must have at least one database backend"
	@exit 1
.endif

.include <bsd.port.post.mk>
