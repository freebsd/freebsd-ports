# New ports collection makefile for:   bacula-web
# Date created:        28 April 2006
# Whom:                Dan Langille <dan@langille.org>
#
# $FreeBSD$
#

PORTNAME=	bacula-web
DISTVERSION=	1.38.9
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/bacula/OldFiles
DISTNAME=	bacula-gui-${DISTVERSION}

MAINTAINER=	dan@langille.org
COMMENT=	Bacula-web provides a summarized output of Bacula jobs

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

NO_BUILD=	yes
USE_PHP=	gd
WANT_PHP_WEB=	yes

OPTIONS=	POSTGRESQL "Use PostgreSQL database instead of MySQL" on

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=yes
SUB_LIST+=		REQ_PGSQL=postgresql
USE_PHP+=		pgsql
.else
CONFIGURE_ARGS+=	--with-mysql=yes
USE_MYSQL=		yes
SUB_LIST+=		REQ_MYSQL=mysql
USE_PHP+=		mysql
.endif

do-install:
	@${ECHO} "Installing in ${PREFIX}/www/bacula-web"
	${MKDIR} ${PREFIX}/www/bacula-web
	${CP} -R ${WRKSRC}/bacula-web/* ${PREFIX}/www/bacula-web
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/bacula-web
	if [ -f ${PREFIX}/www/bacula-web/configs/bacula.conf ]; then \
		${CP} ${PREFIX}/www/bacula-web/configs/bacula.conf ${PREFIX}/etc/bacula-web.conf.sample; \
		${RM} -rf ${PREFIX}/www/bacula-web/configs; \
	fi

	if [ ! -f /var/bacula-web/templates_c ]; then \
		${MKDIR} /var/bacula-web/templates_c; \
		${CHOWN} -R ${WWWOWN}:${WWWGRP} /var/bacula-web/templates_c; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
