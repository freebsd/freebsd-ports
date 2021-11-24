# Created by: Sergei Kolobov <sergei@FreeBSD.org>

PORTNAME=	libpreludedb
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-siem.org/attachments/download/408/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to access Prelude IDMEF database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Very outdated, current version in tree was released back in 2015 and upstream is still active
EXPIRATION_DATE=2022-03-31

LIB_DEPENDS=	libprelude.so:security/libprelude

USES=		compiler:c11 gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-swig \
		--without-python3
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=		yes

MYSQL_DESC=		MySQL plugin
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
PGSQL_DESC=		PostgreSQL plugin
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql
SQLITE_DESC=		SQLite3 plugin
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite3

.include <bsd.port.mk>
