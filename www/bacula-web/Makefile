PORTNAME=	bacula-web
DISTVERSIONPREFIX=	v
DISTVERSION=	8.7.0
PORTREVISION=	1
CATEGORIES=	www sysutils
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bacula-web provides a summarized output of Bacula jobs
WWW=		https://www.bacula-web.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/composer:devel/php-composer@${PHP_FLAVOR}

USES=		php:web,flavors
USE_PHP=	dom gd gettext posix session simplexml tokenizer xml xmlwriter
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL PGSQL SQLITE

SQLITE_USES=	sqlite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USES+=			mysql
CONFIGURE_ARGS+=	--with-mysql=yes
SUB_LIST+=		REQ_MYSQL=mysql
USE_PHP+=		pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=	pgsql
CONFIGURE_ARGS+=	--with-postgresql=yes
SUB_LIST+=		REQ_PGSQL=postgresql
USE_PHP+=		pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite=yes
SUB_LIST+=		REQ_SQLITE=sqlite
USE_PHP+=		pdo_sqlite sqlite3
.endif

do-install:
	# Maybe we should delete some files
	${FIND} ${WRKSRC} -name '*.orig' -delete
	@${ECHO} "Installing in ${WWWDIR}"
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
