# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	mail
MASTER_SITES=	http://www.farrokhi.net/roundcube/:unixified \
		${MASTER_SITE_LOCAL:S/$/:freebsd/g}
MASTER_SITE_SUBDIR=	ale/:freebsd
DISTFILES=	${PORTNAME}-${PORTVERSION:S/.${SNAPSHOT}//}-${SNAPSHOT}${EXTRACT_SUFX}:unixified

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

SNAPSHOT=	20061225

WRKSRC=		${WRKDIR}/${PORTNAME}mail
NO_BUILD=	yes
USE_BZIP2=	yes

WWWOWN?=	www
WWWGRP?=	www
RCUBEDIR?=	www/${PORTNAME}

RCUBEROOT=	${PREFIX}/${RCUBEDIR}
RCUBECOMP=	SQL config index.php logs program skins temp
PORTDOCS=	CHANGELOG INSTALL LICENSE README UPGRADING

PLIST_SUB=	RCUBEDIR=${RCUBEDIR}
SCRIPTS_ENV=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		RCUBEROOT=${RCUBEROOT}

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session

SUB_FILES=	pkg-install
SUB_LIST=	RCUBEROOT=${RCUBEROOT}
PKGDEINSTALL=	${PKGINSTALL}

.if defined(WITH_REPLACE_MAIL_URL) && !empty(WITH_REPLACE_MAIL_URL)
MAIL=		${WITH_REPLACE_MAIL_URL}
REINPLACE_ARGS=	-i ""
.else
MAIL=		mail
.endif
PLIST_SUB+=	MAIL=${MAIL}
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

.if defined(WITH_REPLACE_MAIL_URL)
post-patch:
	@${REINPLACE_CMD} "s/'mail'/'${MAIL}'/g" ${WRKSRC}/index.php \
		${WRKSRC}/program/include/main.inc \
		${WRKSRC}/program/js/app.js
	@${REINPLACE_CMD} "s/_task=mail/_task=${MAIL}/g" \
		${WRKSRC}/program/steps/mail/rss.inc
	@${REINPLACE_CMD} "s/command=\"mail\"/command=\"${MAIL}\"/g" \
		${WRKSRC}/skins/default/includes/header.html \
		${WRKSRC}/skins/default/includes/taskbar.html
	@${REINPLACE_CMD} "s/mail.gif/${MAIL}.gif/g" \
		${WRKSRC}/skins/default/common.css
	@${REINPLACE_CMD} "s/mail.css/${MAIL}.css/g" \
		${WRKSRC}/skins/default/templates/*.html
	@${MV} ${WRKSRC}/skins/default/images/buttons/mail.gif \
		${WRKSRC}/skins/default/images/buttons/${MAIL}.gif
	@${MV} ${WRKSRC}/skins/default/images/buttons/mail.png \
		${WRKSRC}/skins/default/images/buttons/${MAIL}.png
	@${MV} ${WRKSRC}/skins/default/mail.css \
		${WRKSRC}/skins/default/${MAIL}.css
	@${MV} ${WRKSRC}/skins/default/templates/mail.html \
		${WRKSRC}/skins/default/templates/${MAIL}.html
.endif

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
