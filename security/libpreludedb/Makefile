# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpreludedb
PORTVERSION=	1.2.6
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-siem.org/attachments/download/408/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to access Prelude IDMEF database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libprelude.so:security/libprelude

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-swig \
		--without-python3
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS PYTHON
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL
OPTIONS_SUB=		yes

MYSQL_DESC=		MySQL plugin
MYSQL_USE=		mysql=yes
MYSQL_CONFIGURE_WITH=	mysql
PGSQL_DESC=		PostgreSQL plugin
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql
PYTHON_USES=		python:2.7
PYTHON_CONFIGURE_WITH=	python2=${PYTHON_CMD}
PYTHON_PLIST_SUB=	VERSION=${PORTVERSION}
SQLITE_DESC=		SQLite3 plugin
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite3

.include <bsd.port.mk>
