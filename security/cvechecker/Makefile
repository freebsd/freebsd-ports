PORTNAME=	cvechecker
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Check CVE database for vulnerabilities affecting installed packages

LICENSE=	GPLv3

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libconfig.so:devel/libconfig
RUN_DEPENDS=	bash:shells/bash

MAKE_ENV+=	LDADD=-largp

USES=		autoreconf pkgconfig shebangfix

SHEBANG_FILES=	scripts/cverules scripts/cvegenversdat

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/db

bash_OLD_CMD+=	/bin/sh

OPTIONS_DEFINE=			DOCS
OPTIONS_MULTI=			DB
OPTIONS_MULTI_DB=		MYSQL SQLITE
OPTIONS_DEFAULT=		SQLITE
DB_DESC=			CVE Database

MYSQL_USES=			mysql ssl
MYSQL_CONFIGURE_ENABLE=		mysql

SQLITE_USES=			sqlite
SQLITE_CONFIGURE_ENABLE=	sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	sjvermeu

post-stage:
		${MV} ${STAGEDIR}${PREFIX}/etc/cvechecker.conf ${STAGEDIR}${PREFIX}/etc/cvechecker.conf.sample

.include <bsd.port.mk>
