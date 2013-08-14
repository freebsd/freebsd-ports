# $FreeBSD$

PORTNAME=	krecipes
DISTVERSION=	2.0-beta2
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Recipe database for KDE4

LICENSE=	GPLv2

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	SQLITE MYSQL PGSQL
OPTIONS_DEFAULT=	SQLITE

USES=		cmake gettext
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdeprefix kdelibs qimageblitz sharedmime

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
USE_QT4+=	sql-sqlite3_run
.else
CMAKE_ARGS+=	-DWITH_Sqlite:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_QT4+=	sql-mysql_run
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
USE_QT4+=	sql-pgsql_run
.endif

.include <bsd.port.mk>
