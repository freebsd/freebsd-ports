# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
DISTVERSION=	0.2.2
PORTEPOCH=	1
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}mail
DISTNAME=	${PORTNAME}mail-${DISTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

NO_BUILD=	yes

RCUBECOMP=	SQL bin config index.php logs program robots.txt skins temp
PORTDOCS=	CHANGELOG INSTALL LICENSE README UPGRADING

SCRIPTS_ENV=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		WWWDIR=${WWWDIR}

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session iconv dom
IGNORE_WITH_PHP=4

SUB_FILES=	pkg-install
PKGDEINSTALL=	${PKGINSTALL}

REINPLACE_ARGS=	-i ""
.if defined(WITH_REPLACE_MAIL_URL) && !empty(WITH_REPLACE_MAIL_URL)
MAIL=		${WITH_REPLACE_MAIL_URL}
.else
MAIL=		mail
.endif
PLIST_SUB+=	MAIL=${MAIL}

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend" off \
		SSL "Enable SSL support (imaps or google spellcheck)" off \
		LOCALCHECK "Install internal spellchecker" off \
		AUTOCOMP "Enable autocomplete in login form" off

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

.if defined(WITH_SSL)
USE_PHP+=	openssl
.endif

.if defined(WITH_LOCALCHECK)
RCUBECOMP+=	spellchecker.php
USE_PHP+=	pspell simplexml
PLIST_SUB+=	SPELLCHECK=""
.else
PLIST_SUB+=	SPELLCHECK="@comment "
.endif

.if defined(WITH_LOCALCHECK)
post-extract:
	@${CP} ${FILESDIR}/spellchecker.php ${WRKSRC}
.endif

post-patch:
	@${RM} ${WRKSRC}/bin/*.sh
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete
.if defined(WITH_AUTOCOMP)
	@${REINPLACE_CMD} "s/ autocomplete=\"off\"//g" \
		${WRKSRC}/skins/default/templates/login.html
.endif
.if defined(WITH_REPLACE_MAIL_URL)
	@${REINPLACE_CMD} "s/'mail'/'${MAIL}'/g" ${WRKSRC}/index.php \
		${WRKSRC}/program/include/rcmail.php \
		${WRKSRC}/program/localization/*/labels.inc \
		${WRKSRC}/program/steps/addressbook/mailto.inc
	@${REINPLACE_CMD} "s/_task=mail/_task=${MAIL}/g" \
		${WRKSRC}/program/steps/mail/rss.inc
	@${REINPLACE_CMD} "s/\"mail\"/\"${MAIL}\"/g" \
		${WRKSRC}/program/js/app.js \
		${WRKSRC}/skins/default/includes/header.html \
		${WRKSRC}/skins/default/includes/taskbar.html
	@${REINPLACE_CMD} "s/mail.gif/${MAIL}.gif/g" \
		${WRKSRC}/skins/default/common.css
	@${REINPLACE_CMD} "s/mail.css/${MAIL}.css/g" \
		${WRKSRC}/skins/default/templates/*.html
	@${MV} ${WRKSRC}/program/steps/mail \
		${WRKSRC}/program/steps/${MAIL}
	@${MV} ${WRKSRC}/skins/default/images/buttons/mail.gif \
		${WRKSRC}/skins/default/images/buttons/${MAIL}.gif
	@${MV} ${WRKSRC}/skins/default/mail.css \
		${WRKSRC}/skins/default/${MAIL}.css
	@${MV} ${WRKSRC}/skins/default/templates/mail.html \
		${WRKSRC}/skins/default/templates/${MAIL}.html
.endif

do-install:
	-${MKDIR} ${WWWDIR}
.for i in ${RCUBECOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
	@(cd ${WRKSRC}; ${FIND} ${RCUBECOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} ${RCUBECOMP} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm ${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${WWWDIR_REL}' >> ${TMPPLIST}

post-install:
	@${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
