# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	squirrelmail
PORTVERSION=	1.4.22
PORTREVISION=	3
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTVERSION}
DISTNAME=	${PORTNAME}-webmail-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A webmail system which accesses mail over IMAP

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes
### Folks, please stop removing the following line and asking me why
### squirrelmail doesn't work. I know the canned error says that SM
### is incompatible with php 5, but it is just php-5.4 that it is
### incompatible with. Install lang/php53 and it will work.
### This will be fixed if/when the SM team releases the next version.
IGNORE_WITH_PHP=5 # known incompatibilities with php-5.4, use 5.3 for now
DEFAULT_PHP_VER=53

USE_BZIP2=	yes
USES=		gettext

OPTIONS_DEFINE=	DATABASE LDAP
DATABASE_DESC=	PEAR database support (must also intall a driver)

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/${PORTNAME}
SQUIRRELDIR?=	${PREFIX}/www/${PORTNAME}

SMUSER?=	${WWWOWN}
SMGROUP?=	${WWWGRP}
USERS=		${SMUSER}
GROUPS=		${SMGROUP}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	SQUIRRELDIR=${SQUIRRELDIR} SMUSER=${SMUSER} SMGROUP=${SMGROUP}

PORTDOCS=	* .htaccess

CONFLICTS=	squirreloutlook-[0-9]*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATABASE}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

pre-everything::
.if ${PORT_OPTIONS:MDATABASE}
	@${ECHO_CMD} "Note that the PEAR database framework still requires you to install a"
	@${ECHO_CMD} "database-specific PEAR driver, e.g. MySQL."
	@${ECHO_CMD}
.endif

post-patch:
.ifndef PATCH_DEBUG
	@${RM} -f \
		${WRKSRC}/class/deliver/Deliver.class.php.orig \
		${WRKSRC}/config/config_default.php.orig \
		${WRKSRC}/functions/global.php.orig \
		${WRKSRC}/functions/i18n.php.orig \
		${WRKSRC}/functions/imap_search.php.orig \
		${WRKSRC}/src/addrbook_search_html.php.orig \
		${WRKSRC}/src/compose.php.orig
.endif
	@${REINPLACE_CMD} -e 's|ispell|${LOCALBASE}/bin/ispell|g' \
		${WRKSRC}/plugins/squirrelspell/sqspell_config.php
	@${REINPLACE_CMD} -e 's|/usr/bin/fortune|/usr/games/fortune|g' \
		${WRKSRC}/plugins/fortune/fortune_functions.php
	@${RM} ${WRKSRC}/plugins/squirrelspell/sqspell_config.php.bak \
		${WRKSRC}/plugins/fortune/fortune_functions.php.bak

# Rearrange the documentation
do-build:
	@${MV} ${WRKSRC}/themes/README.themes ${WRKSRC}/doc/
	@cd ${WRKSRC} ; for f in `${FIND} plugins -name "README*" -or \
		-name INSTALL -or -name CHANGES -or -name HISTORY`; \
		do \
		${MKDIR} doc/`dirname $$f` ; \
		${MV} $$f doc/`dirname $$f` ; \
	done; \
	${MV} doc/plugins/squirrelspell/doc/README doc/plugins/squirrelspell ; \
	${RM} -rf doc/plugins/squirrelspell/doc ; \
	${MV} plugins/squirrelspell/doc/* doc/plugins/squirrelspell ; \
	${RM} -f doc/plugins/squirrelspell/index.php ; \
	${RM} -rf plugins/squirrelspell/doc
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${ECHO} "left_refresh=300" >> ${WRKSRC}/data/default_pref
	@${MV} ${WRKSRC}/config/config_local.php ${WRKSRC}/config/config_local.php.sample

do-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${FILESDIR}/111.clean-squirrelmail ${PREFIX}/etc/periodic/daily
	${MKDIR} ${SQUIRRELDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${SQUIRRELDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/configure ${SQUIRRELDIR}
.for DIR in class config data functions help images include locale plugins po src themes
	cd ${WRKSRC} && ${FIND} ${DIR} | ${CPIO} -pdmu --quiet ${SQUIRRELDIR}
.endfor
	${CHOWN} -R ${SMUSER}:${SMGROUP} ${SQUIRRELDIR}/data
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | ${CPIO} -pdmu --quiet ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
