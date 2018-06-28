# $FreeBSD$

PORTNAME=	krecipes
DISTVERSION=	2.0-beta2
PORTREVISION=	11
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 recipe database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gettext kde:4 qt:4 shared-mime-info
USE_GNOME=	libxml2 libxslt
USE_QT=		corelib dbus gui qt3support sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs qimageblitz

LDFLAGS+=	-Wl,--as-needed

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=		qt:4 sqlite
SQLITE_USE=		QT=sql-sqlite3_run
SQLITE_CMAKE_BOOL=	WITH_Sqlite

MYSQL_USES=		mysql qt:4
MYSQL_USE=		QT=sql-mysql_run

PGSQL_USES=		pgsql qt:4
PGSQL_USE=		QT=sql-pgsql_run

.include <bsd.port.mk>
