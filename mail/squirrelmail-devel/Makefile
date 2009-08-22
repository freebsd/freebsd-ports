# New ports collection makefile for:	squirrelmail
# Date created: 			17 March 2006
# Whom: 				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMESUFFIX=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		all_locales-${PORTVERSION}-20060219${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	simond@irrelevant.org
COMMENT=	A webmail system which accesses mail over IMAP (Development version)

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes

USE_BZIP2=	yes

.ifdef WITH_DATABASE
RUN_DEPENDS+=	${PREFIX}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.ifdef WITH_LDAP
USE_PHP+=	ldap
.endif

SQUIRRELDEVELDIR?=	${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		SQUIRRELDEVELDIR="${SQUIRRELDEVELDIR:S,^${PREFIX}/,,}"

SUB_FILES+=	pkg-message pkg-install pkg-deinstall
SUB_LIST+=	SQUIRRELDEVELDIR="${SQUIRRELDEVELDIR}"

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

pre-everything::
	@${ECHO_CMD} "Use WITH_LDAP to ensure PHP LDAP support is installed"
	@${ECHO_CMD} "Use WITH_DATABASE to ensure PEAR framework for database support is installed"
	@${ECHO_CMD} "   (note that this does not install the database specific PEAR support, e.g. MySQL)"
	@${ECHO_CMD}

post-patch:
.ifndef PATCH_DEBUG
	@${RM} -f ${WRKSRC}/config/config_default.php.orig
.endif
	@${FIND} ${WRKSRC} -name '*.orig' -delete
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
	@${ECHO} "left_refresh=300" >> ${WRKSRC}/config/default_pref
	@${CP} -r ${WRKSRC}/../locale ${WRKSRC}
	@${CP} -r ${WRKSRC}/../images ${WRKSRC}
	@${CP} -r ${WRKSRC}/../help ${WRKSRC}

pre-install:
	@${ECHO} "Your umask should be lax while installing this. Like, 022 or something."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${FILESDIR}/111.clean-squirrelmail ${PREFIX}/etc/periodic/daily
	${MKDIR} ${SQUIRRELDEVELDIR}
	@${CP} -pv ${WRKSRC}/index.php ${SQUIRRELDEVELDIR}
	@${CP} -pv ${WRKSRC}/configure ${SQUIRRELDEVELDIR}
.for DIR in class config functions help images include locale plugins po src templates themes
	@${CP} -rpv ${WRKSRC}/${DIR} ${SQUIRRELDEVELDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/doc/* ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
