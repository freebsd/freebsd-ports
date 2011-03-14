# ports collection makefile for:	krecipies
# Date created:				19 March 2005
# Whom:					hank
#
# $FreeBSD$
#

PORTNAME=	krecipes
DISTVERSION=	2.0-beta2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Recipe database for KDE4

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz

LATEST_LINK=	${PORTNAME}-kde4

USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdeprefix kdelibs sharedmime
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	SQLITE "Support for SQLite backend" on \
		MYSQL "Support for MySQL backend" off \
		POSTGRESQL "Support for PostgreSQL backend" off

.include <bsd.port.options.mk>

.if defined(WITHOUT_SQLITE)
CMAKE_ARGS+=	-DWITH_Sqlite:BOOL=OFF
.else
USE_SQLITE=	yes
QT_COMPONENTS+=	sql-sqlite3_run
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
QT_COMPONENTS+=	sql-mysql_run
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
QT_COMPONENTS+=	sql-pgsql_run
.endif

pre-configure:

.if defined(WITHOUT_SQLITE) && !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
IGNORE=	at least one database backend must be selected, run 'make config' and select a database
.endif

.include <bsd.port.mk>
