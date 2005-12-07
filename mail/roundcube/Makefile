# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
PORTVERSION=	0.1
PORTREVISION=	${SNAPSHOT}
CATEGORIES=	mail
MASTER_SITES=	http://www.unixified.net/roundcube/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${SNAPSHOT}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

SNAPSHOT=	20051204

WRKSRC=		${WRKDIR}/${PORTNAME}mail
NO_BUILD=	yes

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

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off

.if defined(PHP_VER) && ${PHP_VER} == 5
OPTIONS+=       SQLITE "Use SQLite backend" off
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

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
