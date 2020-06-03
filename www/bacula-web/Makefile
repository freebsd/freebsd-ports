# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula-web
DISTVERSIONPREFIX=	v
DISTVERSION=	8.4.0
PORTREVISION=	0
CATEGORIES=	www sysutils
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Bacula-web provides a summarized output of Bacula jobs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/composer:devel/php-composer@${PHP_FLAVOR}

USES=		php:web,flavors
USE_PHP=	dom gd gettext session simplexml tokenizer xml xmlwriter
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL

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
USE_PHP+=		pdo_sqlite
.endif

do-install:
	# Maybe we should delete some files
	${FIND} ${WRKSRC} -name '*.orig' -delete
	@${ECHO} "Installing in ${WWWDIR}"
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

.include <bsd.port.mk>
