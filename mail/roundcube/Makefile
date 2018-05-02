# $FreeBSD$

PORTNAME=	roundcube
DISTVERSION=	1.3.6
PORTEPOCH=	1
CATEGORIES?=	mail www
MASTER_SITES=	https://github.com/roundcube/roundcubemail/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}mail-${DISTVERSION}-complete
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER?=	ale@FreeBSD.org
COMMENT=	Fully skinnable XHTML/CSS webmail written in PHP

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}mail-${DISTVERSION}

RCUBECOMP=	SQL config .htaccess index.php installer logs \
		plugins program skins temp vendor
PORTDOCS=	CHANGELOG INSTALL README.md UPGRADING

USES=		cpe php:web,flavors
CPE_PRODUCT=	webmail
CPE_VENDOR=	roundcube

USE_PHP=	pcre mbstring session iconv dom xml json intl zip filter openssl fileinfo exif

OPTIONS_DEFINE=	LDAP GD PSPELL NSC DOCS
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=MYSQL

DB_DESC=	Database backend
MYSQL_DESC=	Use MySQL backend
PGSQL_DESC=	Use PostgreSQL backend
SQLITE_DESC=	Use SQLite backend
LDAP_DESC=	Enable LDAP support (address book)
GD_DESC=	Enable GD support (image conversion)
PSPELL_DESC=	Enable PSpell support (internal spellcheck)
NSC_DESC=	Install network spellchecker

GD_VARS=	use_php+=gd
LDAP_VARS=	use_php+=ldap
MYSQL_VARS=	use_php+=pdo_mysql
NSC_IMPLIES=	PSPELL
NSC_VARS=	use_php+=simplexml rcubecomp+=spellchecker.php
PGSQL_VARS=	use_php+=pdo_pgsql
PSPELL_VARS=	use_php+=pspell
SQLITE_VARS=	use_php+=pdo_sqlite

post-extract-NSC:
	@${CP} ${FILESDIR}/spellchecker.php ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -type f -delete

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${STAGEDIR}${WWWDIR}
.for i in ${RCUBECOMP}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${WWWDIR}
.endfor
	@(cd ${WRKSRC}; ${FIND} bin ${RCUBECOMP} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,${WWWDIR_REL}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec chown ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/logs' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@postexec chown ${WWWOWN}:${WWWGRP} %D/${WWWDIR_REL}/temp' \
		>> ${TMPPLIST}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
