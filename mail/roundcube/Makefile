# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	mail
MASTER_SITES=	http://www.unixified.net/roundcube/:unixified \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	flz/${PORTNAME}/:freebsd
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.${SNAPSHOT}//}-${SNAPSHOT}${EXTRACT_SUFX}:freebsd

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

SNAPSHOT=	20060518

WRKSRC=		${WRKDIR}/${PORTNAME}mail
NO_BUILD=	yes
USE_BZIP2=	yes

WWWOWN?=	www
WWWGRP?=	www
RCUBEDIR?=	www/${PORTNAME}

RCUBEROOT=	${PREFIX}/${RCUBEDIR}
RCUBECOMP=	SQL config index.php logs program skins temp
PORTDOCS=	CHANGELOG INSTALL LICENSE README

PLIST_SUB=	RCUBEDIR=${RCUBEDIR}
SCRIPTS_ENV=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		RCUBEROOT=${RCUBEROOT}

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session

SUB_FILES=	pkg-install
SUB_LIST=	RCUBEROOT=${RCUBEROOT}
PKGDEINSTALL=	${PKGINSTALL}

LOCALBASE?=	/usr/local

.if exists(${LOCALBASE}/etc/php.conf)
.include "${LOCALBASE}/etc/php.conf"
.endif

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=	SQLITE "Use SQLite backend" off
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE)
IGNORE=		needs a database backend
.endif

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

# Avoid INDEX breakage when WITHOUT_MYSQL is defined.
USE_PHP?=	yes

.include "${PORTSDIR}/Mk/bsd.php.mk"

do-install:
	${MKDIR} ${RCUBEROOT}
.for i in ${RCUBECOMP}
	${CP} -Rp ${WRKSRC}/${i} ${RCUBEROOT}/
.endfor
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCSDIR}/
.if !defined(NOPORTDOCS)
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

post-install:
	@${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
