# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	squirrelmail
PORTVERSION=	20131026
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw/squirrelmail
DISTNAME=	${PORTNAME}-${PORTVERSION}_0200-SVN.stable
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A webmail system which accesses mail over IMAP

LICENSE=	GPLv2

# This snapshot tarball contains php 5.4 and 5.5 compatibility
# patches, but the only guaranteed compatibility is with php 5.3.
# If you encounter problems, downgrade to php 5.3.

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes

USE_BZIP2=	yes
USES=		gettext

WRKSRC=		${WRKDIR}/${PORTNAME}.stable/${PORTNAME}

OPTIONS_DEFINE=	DATABASE LDAP
DATABASE_DESC=	PEAR database support (must also install a driver)

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/squirrelmail
SQUIRRELDIR?=	${WWWDIR}

SMUSER?=	${WWWOWN}
SMGROUP?=	${WWWGRP}
USERS=		${SMUSER}
GROUPS=		${SMGROUP}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
			SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}" \

SUB_FILES=	pkg-message
SUB_LIST=	SQUIRRELDIR=${SQUIRRELDIR} SMUSER=${SMUSER} SMGROUP=${SMGROUP}

CONFLICTS=	squirreloutlook-[0-9]*

DATABASE_RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB

.include <bsd.port.options.mk>

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
	@${REINPLACE_CMD} -e 's|ispell|${LOCALBASE}/bin/ispell|g' \
		${WRKSRC}/plugins/squirrelspell/sqspell_config.php
	@${REINPLACE_CMD} -e 's|/usr/bin/fortune|/usr/games/fortune|g' \
		${WRKSRC}/plugins/fortune/fortune_functions.php
	@${REINPLACE_CMD} -e 's|/var/local/squirrelmail|${SQUIRRELDIR}|g' \
		${WRKSRC}/config/conf.pl ${WRKSRC}/config/config_default.php ${WRKSRC}/doc/INSTALL

do-build:
# Rearrange the documentation
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

	@${ECHO} "left_refresh=300" >> ${WRKSRC}/data/default_pref
	@${MV} ${WRKSRC}/config/config_local.php ${WRKSRC}/config/config_local.php.sample
	@${MV} ${WRKSRC}/data/default_pref ${WRKSRC}/data/default_pref-dist
	@${MKDIR} ${WRKSRC}/attach
	@${CP} -p ${WRKSRC}/data/.htaccess ${WRKSRC}/attach/.htaccess

pre-install:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${FILESDIR}/111.clean-squirrelmail ${STAGEDIR}${PREFIX}/etc/periodic/daily
	@${MKDIR} ${STAGEDIR}${SQUIRRELDIR}
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${SQUIRRELDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/configure ${STAGEDIR}${SQUIRRELDIR}
	cd ${WRKSRC} && \
		${FIND} attach class config data functions help images include locale plugins po src themes \
		| ${CPIO} -pdmu --quiet ${STAGEDIR}${SQUIRRELDIR}
	${CHOWN} ${SMUSER}:${SMGROUP} ${STAGEDIR}${SQUIRRELDIR}/data ${STAGEDIR}${SQUIRRELDIR}/attach
	${CHMOD} 730 ${STAGEDIR}${SQUIRRELDIR}/attach
	${CHMOD} 750 ${STAGEDIR}${SQUIRRELDIR}/data

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | ${CPIO} -pdmu --quiet ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
