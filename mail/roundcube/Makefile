# New ports collection makefile for:	roundcube
# Date created:				Oct 21 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	roundcube
DISTVERSION=	0.8.0
PORTEPOCH=	1
CATEGORIES?=	mail www
MASTER_SITES=	SF/${PORTNAME}mail/${PORTNAME}mail/${DISTVERSION:U}
DISTNAME=	${PORTNAME}mail-${DISTVERSION}

MAINTAINER?=	ale@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

LICENSE=	GPLv3

NO_BUILD=	yes
CONFLICTS=	ja-roundcube-[0-9]*

RCUBECOMP=	.htaccess SQL config index.php installer logs plugins program robots.txt skins temp
PORTDOCS=	CHANGELOG INSTALL README.md UPGRADING

SCRIPTS_ENV=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} \
		WWWDIR=${WWWDIR}

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session iconv dom xml json intl
IGNORE_WITH_PHP=4

OPTIONS_DEFINE=	SSL LDAP GD PSPELL NSC
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

MYSQL_DESC=	Use MySQL backend
PGSQL_DESC=	Use PostgreSQL backend
SQLITE_DESC=	Use SQLite backend (needs PHP 5.3 or below)
SSL_DESC=	Enable SSL support (imaps or google spellcheck)
LDAP_DESC=	Enable LDAP support (address book)
GD_DESC=	Enable GD support (image convertion)
PSPELL_DESC=	Enable PSpell support (internal spellcheck)
NSC_DESC=	Install network spellchecker

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite
.endif

.if ${PORT_OPTIONS:MSSL}
USE_PHP+=	openssl
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MPSPELL} || ${PORT_OPTIONS:MNSC}
USE_PHP+=	pspell
.endif

.if ${PORT_OPTIONS:MNSC}
RCUBECOMP+=	spellchecker.php
USE_PHP+=	simplexml
PLIST_SUB+=	SPELLCHECK=""
.else
PLIST_SUB+=	SPELLCHECK="@comment "
.endif

.if ${PORT_OPTIONS:MNSC}
post-extract:
	@${CP} ${FILESDIR}/spellchecker.php ${WRKSRC}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete

do-install:
	-${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${WWWDIR}
.for i in ${RCUBECOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/logs ${WWWDIR}/temp
.if ${PORT_OPTIONS:MDOCS}
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
