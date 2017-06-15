# $FreeBSD$

PORTNAME=	krecipes
DISTVERSION=	2.0-beta2
PORTREVISION=	8
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 recipe database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gettext kde:4 shared-mime-info
USE_GNOME=	libxml2 libxslt
USE_QT4=	corelib dbus gui qt3support sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs qimageblitz

LDFLAGS+=	-Wl,--as-needed

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=		sqlite
SQLITE_USE=		QT4=sql-sqlite3_run
SQLITE_CMAKE_BOOL=	WITH_Sqlite

MYSQL_USES=		mysql
MYSQL_USE=		QT4=sql-mysql_run

PGSQL_USES=		pgsql
PGSQL_USE=		QT4=sql-pgsql_run

.include <bsd.port.mk>
