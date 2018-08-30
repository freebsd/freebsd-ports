# $FreeBSD$

PORTNAME=	krecipes
PORTVERSION=	2.1.0
CATEGORIES=	misc kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 recipe database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake gettext kde:4 qt:4 shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt
USE_QT=		corelib dbus gui qt3support sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs

LDFLAGS+=	-Wl,--as-needed

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=		sqlite
SQLITE_USE=		QT=sql-sqlite3_run

MYSQL_USES=		mysql
MYSQL_USE=		QT=sql-mysql_run

PGSQL_USES=		pgsql
PGSQL_USE=		QT=sql-pgsql_run

.include <bsd.port.mk>
