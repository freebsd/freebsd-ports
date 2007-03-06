# New ports collection makefile for:	ojs
# Date created:				4 March 2006
# Whom:					Filipe Rocha <filiperocha@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ojs2
PORTVERSION=	2.1.1
CATEGORIES=	www
MASTER_SITES=	http://pkp.sfu.ca/ojs/download/
DISTNAME=	ojs-2.1.1

MAINTAINER=	filiperocha@gmail.com
COMMENT=	Open Journal Systems

DIST_SUBDIR=	${PORTNAME}

NO_BUILD=	yes
USE_PHP=	mbstring
WANT_PHP_WEB=	yes

OJSDIR?=	www/ojs2

OPTIONS=	MYSQL "Use a MYSQL Database" on \
		PGSQL "Use a PostgreSQL Database" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=		needs at least least one DB backend; please run 'make config'
.endif

.ifndef(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.ifdef(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

do-install:
	@${INSTALL_DATA} -d ${PREFIX}/${OJSDIR}
	@${CP} -Rn ${WRKSRC}/* ${PREFIX}/${OJSDIR}
	@${FIND} ${PREFIX}/${OJSDIR} -type d -exec ${CHMOD} a+x {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/cache/t_cache/ -type d -exec ${CHMOD} -R +rw {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/cache/t_compile/ -type d -exec ${CHMOD} -R +rw {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/cache/t_config/ -type d -exec ${CHMOD} -R +rw {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/cache/_db/ -type d -exec ${CHMOD} -R +rw {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/config.inc.php -type d -exec ${CHMOD} -R +rw {} \;
	@${FIND} ${PREFIX}/${OJSDIR}/public/ -type d -exec ${CHMOD} -R +rw {} \;
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${OJSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
