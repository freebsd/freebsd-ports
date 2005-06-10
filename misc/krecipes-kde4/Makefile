# ports collection makefile for: krecipies
# Date created:                  19 March 2005
# Whom:                          hank
#
# $FreeBSD$
#

PORTNAME=	krecipes
PORTVERSION=	0.7.1
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	krecipes_beta_0.7.1

MAINTAINER=	hank@millerfarm.com
COMMENT=	Recipe database for cooks

OPTIONS+=	SQLITE "Support for sqlite backend" on
OPTIONS+=	MYSQL "Support for MySQL backend" off
OPTIONS+=	POSTGRESQL "Support for PostgreSQL backend" off

USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/krecipes-0.7.1

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile.
.endif

.if defined(WITHOUT_SQLITE)
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQLITE="@comment "
.else
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
.endif

.if defined(WITH_POSTGRESQL)
RUN_DEPENDS+=	${X11BASE}/lib/plugins/sqldrivers/libqsqlpsql.so:${PORTSDIR}/databases/qt-pgsql-plugin
.endif

pre-configure:
.  if defined(WITHOUT_SQLITE) && !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
	@${ECHO} "You must have at least one database backend"
	@exit 1
.  endif

.include <bsd.port.post.mk>
