# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
DISTVERSION=	0.7.2
PORTEPOCH=	1
CATEGORIES?=	mail www
MASTER_SITES=	SF/${PORTNAME}mail/${PORTNAME}mail/${DISTVERSION:U}
DISTNAME=	${PORTNAME}mail-${DISTVERSION}

MAINTAINER?=	ale@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

LICENSE=	GPLv2

NO_BUILD=	yes
CONFLICTS=	ja-roundcube-[0-9]*

RCUBECOMP=	.htaccess SQL config index.php installer logs plugins program robots.txt skins temp
PORTDOCS=	CHANGELOG INSTALL README UPGRADING

SCRIPTS_ENV=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		WWWDIR=${WWWDIR}

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session iconv dom xml json intl
IGNORE_WITH_PHP=4

REINPLACE_ARGS=	-i ""
.if defined(WITH_REPLACE_MAIL_URL) && !empty(WITH_REPLACE_MAIL_URL)
MAIL=		${WITH_REPLACE_MAIL_URL}
.else
MAIL=		mail
.endif
PLIST_SUB+=	MAIL=${MAIL}

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend (needs PHP 5.3 or below)" off \
		SSL "Enable SSL support (imaps or google spellcheck)" off \
		LDAP "Enable LDAP support (address book)" off \
		PSPELL "Enable PSpell support (internal spellcheck)" off \
		NSC "Install network spellchecker" off

.include <bsd.port.options.mk>

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

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_PSPELL) || defined(WITH_NSC)
USE_PHP+=	pspell
.endif

.if defined(WITH_NSC)
RCUBECOMP+=	spellchecker.php
USE_PHP+=	simplexml
PLIST_SUB+=	SPELLCHECK=""
.else
PLIST_SUB+=	SPELLCHECK="@comment "
.endif

.if defined(WITH_NSC)
post-extract:
	@${CP} ${FILESDIR}/spellchecker.php ${WRKSRC}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete
.if defined(WITH_REPLACE_MAIL_URL)
	@${REINPLACE_CMD} "s/'mail'/'${MAIL}'/g" ${WRKSRC}/index.php \
		${WRKSRC}/plugins/*/*.php \
		${WRKSRC}/program/include/rcmail.php \
		${WRKSRC}/program/js/editor.js \
		${WRKSRC}/program/localization/*/labels.inc \
		${WRKSRC}/program/steps/addressbook/mailto.inc \
		${WRKSRC}/skins/default/functions.js \
		${WRKSRC}/skins/default/includes/links.html
	@${REINPLACE_CMD} "s/'mail|/'${MAIL}|/g" ${WRKSRC}/plugins/*/*.php
	@${REINPLACE_CMD} "s/|mail'/|${MAIL}'/g" ${WRKSRC}/plugins/*/*.php
	@${REINPLACE_CMD} "s/_task=mail/_task=${MAIL}/g" \
		${WRKSRC}/program/js/app.js
	@${REINPLACE_CMD} "s/\"mail\"/\"${MAIL}\"/g" \
		${WRKSRC}/program/js/app.js \
		${WRKSRC}/skins/default/includes/taskbar.html
	@${REINPLACE_CMD} "s/\"mail\//\"${MAIL}\//g" \
		${WRKSRC}/program/js/app.js
	@${REINPLACE_CMD} "s/mail_footer/${MAIL}_footer/g" \
		${WRKSRC}/skins/default/*.css \
		${WRKSRC}/skins/default/templates/login.html
	@${REINPLACE_CMD} "s/mail_toolbar/${MAIL}_toolbar/g" \
		${WRKSRC}/skins/default/*.css \
		${WRKSRC}/skins/default/templates/login.html
	@${MV} ${WRKSRC}/program/steps/mail \
		${WRKSRC}/program/steps/${MAIL}
	@${MV} ${WRKSRC}/skins/default/images/mail_footer.gif \
		${WRKSRC}/skins/default/images/${MAIL}_footer.gif
	@${MV} ${WRKSRC}/skins/default/images/mail_footer.png \
		${WRKSRC}/skins/default/images/${MAIL}_footer.png
	@${MV} ${WRKSRC}/skins/default/images/mail_toolbar.gif \
		${WRKSRC}/skins/default/images/${MAIL}_toolbar.gif
	@${MV} ${WRKSRC}/skins/default/images/mail_toolbar.png \
		${WRKSRC}/skins/default/images/${MAIL}_toolbar.png
	@${MV} ${WRKSRC}/skins/default/mail.css \
		${WRKSRC}/skins/default/${MAIL}.css
	@${MV} ${WRKSRC}/skins/default/templates/mail.html \
		${WRKSRC}/skins/default/templates/${MAIL}.html
.endif

do-install:
	-${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${WWWDIR}
.for i in ${RCUBECOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/logs ${WWWDIR}/temp
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
	@(cd ${WRKSRC}; ${FIND} bin ${RCUBECOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} bin ${RCUBECOMP} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm ${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${WWWDIR_REL}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
