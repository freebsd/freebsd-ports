PORTNAME=	libpreludedb
DISTVERSION=	5.2.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	https://www.prelude-siem.org/attachments/download/1393/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library to access Prelude IDMEF database
WWW=		https://github.com/Prelude-SIEM/libpreludedb

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream project is dead
EXPIRATION_DATE=	2026-07-30

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libltdl.so:devel/libltdl \
		libpcre.so:devel/pcre \
		libprelude.so:security/libprelude \
		libunwind.so:devel/libunwind

USES=		gmake libtool python shebangfix ssl
USE_LDCONFIG=	yes

SHEBANG_FILES=	preludedb-admin

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-swig
CONFIGURE_ENV=	PYTHON3=${PYTHON_CMD}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	MYSQL
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_SUB=		yes

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgresql
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite3

.include <bsd.port.mk>
