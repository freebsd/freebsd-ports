# New ports collection makefile for:	squirrelmailoutlook
# Date created: 			28 December 2006
# Whom: 				Dennis Cabooter <freebsd@rootxs.org>
#
# $FreeBSD$
#

PORTNAME=	squirreloutlook
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/${PORTVERSION}
			squirrelmail
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		all_locales-1.5.1-20060409${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A webmail system which accesses mail over IMAP

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes
USE_GETTEXT=	yes

.ifdef WITH_DATABASE
RUN_DEPENDS+=	${PREFIX}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.ifdef WITH_LDAP
USE_PHP+=	ldap
.endif

SQUIRRELDIR=	${PREFIX}/www/${PORTNAME}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	SQUIRRELDIR=${SQUIRRELDIR}

PORTDOCS=	*

CONFLICTS=	squirrelmail-[0-9]*

pre-everything::
	@${ECHO_CMD} "Use WITH_LDAP to ensure PHP LDAP support is installed"
	@${ECHO_CMD} "Use WITH_DATABASE to ensure PEAR framework for database support is installed"
	@${ECHO_CMD} "   (note that this does not install the database specific PEAR support, e.g. MySQL)"
	@${ECHO_CMD}

post-patch:
.ifndef PATCH_DEBUG
	@${RM} -f ${WRKSRC}/config/config_default.php.orig ${WRKSRC}/functions/global.php.orig
.endif
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
	@${CP} -pv ${WRKSRC}/index.php ${SQUIRRELDIR}
	@${CP} -pv ${WRKSRC}/configure ${SQUIRRELDIR}
.for DIR in class config data functions help images include locale plugins po src themes
	@${CP} -rpv ${WRKSRC}/${DIR} ${SQUIRRELDIR}
.endfor
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${SQUIRRELDIR}/data
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/doc/* ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
