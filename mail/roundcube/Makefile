# $FreeBSD$

PORTNAME=	roundcube
DISTVERSION=	0.9.5
PORTEPOCH=	1
CATEGORIES?=	mail www
MASTER_SITES=	SF/${PORTNAME}mail/${PORTNAME}mail/${DISTVERSION:U}
DISTNAME=	${PORTNAME}mail-${DISTVERSION}

MAINTAINER?=	ale@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

LICENSE=	GPLv3

NO_BUILD=	yes

RCUBECOMP=	SQL config index.php installer logs plugins program robots.txt skins temp
PORTDOCS=	CHANGELOG INSTALL README.md UPGRADING

WANT_PHP_WEB=	yes
USE_PHP=	pcre mbstring session iconv dom xml json intl zip filter
IGNORE_WITH_PHP=52

OPTIONS_DEFINE=	SSL LDAP GD PSPELL NSC DOCS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

MYSQL_DESC=	Use MySQL backend
PGSQL_DESC=	Use PostgreSQL backend
SQLITE_DESC=	Use SQLite backend
SSL_DESC=	Enable SSL support (imaps or google spellcheck)
LDAP_DESC=	Enable LDAP support (address book)
GD_DESC=	Enable GD support (image conversion)
PSPELL_DESC=	Enable PSpell support (internal spellcheck)
NSC_DESC=	Install network spellchecker

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
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
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR}
.for i in ${RCUBECOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif
	@(cd ${WRKSRC}; ${FIND} bin ${RCUBECOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec chown ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/logs' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec chown ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/temp' \
		>> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} bin ${RCUBECOMP} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm ${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${WWWDIR_REL}' >> ${TMPPLIST}

.include <bsd.port.mk>
