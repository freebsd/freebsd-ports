# New ports collection makefile for:	squirrelmail
# Date created: 			27 December 2001
# Whom: 				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION?=	1.4.5
CATEGORIES?=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	squirrelmail
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		all_locales-${PORTVERSION}-20050713${EXTRACT_SUFX}
DIST_SUBDIR=	squirrelmail

MAINTAINER?=	simond@irrelevant.org
COMMENT?=	A webmail system which accesses mail over IMAP

CONFLICTS?=	ja-squirrelmail-1.*

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes

USE_BZIP2=	yes
USE_REINPLACE=	yes

.ifdef WITH_DATABASE
WANT_PHP_PEAR=	yes
RUN_DEPENDS+=	${PREFIX}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.ifdef WITH_LDAP
USE_PHP+=	ldap
.endif

.ifndef WITHOUT_WWWDIR
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
.else
SQUIRRELDIR?=	${PREFIX}/squirrelmail
.endif

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

pre-everything::
	@${ECHO_CMD} "SquirrelMail is installed into ${SQUIRRELDIR}"
	@${ECHO_CMD} "To use the old location ${PREFIX}/squirrelmail define"
	@${ECHO_CMD} "WITHOUT_WWWDIR when patching or installing"
	@${ECHO_CMD}
	@${ECHO_CMD} "Use WITH_LDAP to ensure PHP LDAP support is installed"
	@${ECHO_CMD} "Use WITH_DATABASE to ensure PEAR framework for database support is installed"
	@${ECHO_CMD} "   (note that this does not install the database specific PEAR support, e.g. MySQL)"
	@${ECHO_CMD}

.if !target(slaveport-post-patch)
slaveport-post-patch:
.endif

post-patch: slaveport-post-patch
.ifndef PATCH_DEBUG
	@${RM} -f ${WRKSRC}/config/config_default.php.orig
.endif
	@${SED} -e "s;%%SQUIRRELDIR%%;${SQUIRRELDIR};g" \
		${MASTERDIR}/pkg-install > ${PKGINSTALL}
	@${SED} -e "s;%%SQUIRRELDIR%%;${SQUIRRELDIR};g" \
		${MASTERDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} -e "s;%%SQUIRRELDIR%%;${SQUIRRELDIR};g" \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|ispell|${LOCALBASE}/bin/ispell|g' \
		${WRKSRC}/plugins/squirrelspell/sqspell_config.php
	@${RM} ${WRKSRC}/plugins/squirrelspell/sqspell_config.php.bak

# Rearrange the documentation
do-build:
.for file in AUTHORS ChangeLog COPYING INSTALL README UPGRADE
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/doc/
.endfor
	@${MV} ${WRKSRC}/ReleaseNotes ${WRKSRC}/doc/ReleaseNotes-${PORTVERSION}.txt
	@${MV} ${WRKSRC}/themes/README.themes ${WRKSRC}/doc/
	@cd ${WRKSRC} ; for f in `find plugins -name "README*" -or \
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
	@${CP} -r ${WRKSRC}/../locale ${WRKSRC}
	@${CP} -r ${WRKSRC}/../images ${WRKSRC}
	@${CP} -r ${WRKSRC}/../help ${WRKSRC}

pre-install:
	@${ECHO} "Your umask should be lax while installing this. Like, 022 or something."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${FILESDIR}/111.clean-squirrelmail ${PREFIX}/etc/periodic/daily
	${MKDIR} ${SQUIRRELDIR}
	${CP} -p ${WRKSRC}/index.php ${SQUIRRELDIR}
	${CP} -p ${WRKSRC}/configure ${SQUIRRELDIR}
.for DIR in class config data functions help images include locale plugins po src themes
	${CP} -rp ${WRKSRC}/${DIR} ${SQUIRRELDIR}
.endfor
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${SQUIRRELDIR}/data
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
