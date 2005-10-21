# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}mail
DISTNAME=	${PORTNAME}_webmail_${PORTVERSION}-${SNAPSHOT}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

SNAPSHOT=	20051007

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

WANT_PHP_MOD=	yes

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

pre-install:
	@${MV} ${WRKSRC}/config/db.inc.php ${WRKSRC}/config/db.inc.php.sample
	@${MV} ${WRKSRC}/config/main.inc.php ${WRKSRC}/config/main.inc.php.sample

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

.include <bsd.port.mk>
