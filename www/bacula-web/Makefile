# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula-web
DISTVERSION=	7.2.0
PORTREVISION=	2
CATEGORIES=	www sysutils
MASTER_SITES=	http://www.bacula-web.org/files/bacula-web.org/downloads/

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Bacula-web provides a summarized output of Bacula jobs

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=		php:web tar:tgz
USE_PHP=	gd gettext session
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

BACULAWEB_HOME?=${WWWDIR}
BASE=		${BACULAWEB_HOME:S|${PREFIX}/||}
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} BASE=${BASE}
SUB_LIST=	BASE=${BASE}

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
	@${ECHO} "Installing in ${BACULAWEB_HOME}"
	${MKDIR} ${STAGEDIR}${BACULAWEB_HOME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} application \
		${STAGEDIR}${BACULAWEB_HOME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} core ${STAGEDIR}${BACULAWEB_HOME}
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${BACULAWEB_HOME}

.include <bsd.port.mk>
