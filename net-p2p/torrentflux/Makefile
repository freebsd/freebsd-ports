# New ports collection makefile for:	torrentflux
# Date created:				27 Sep 2005
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		torrentflux
DISTVERSION=		2.0beta1
CATEGORIES=		net-p2p www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A PHP based BitTorrent client that runs on a web server

RUN_DEPENDS=		${LOCALBASE}/share/adodb/adodb.inc.php:${PORTSDIR}/databases/adodb \
			${LOCALBASE}/bin/sqlite:${PORTSDIR}/databases/sqlite2 \
			${LOCALBASE}/bin/btshowmetainfo.py:${PORTSDIR}/net-p2p/py-bittornado-core

NO_PACKAGE=		dependencies need manual installation, see ${FILESDIR}/install.txt.in

USE_PHP=		pcre session sqlite
WANT_PHP_WEB=		yes
DEFAULT_PHP_VER?=	5
BROKEN_WITH_PHP=	4
USE_PYTHON_RUN=		yes

EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-*

SUB_FILES=		pkg-install pkg-deinstall pkg-message torrentflux.sh
SUB_LIST=		DOWNLOADS=${WITH_TF_DATADIR} \
			DATABASE=${WITH_TF_DBDIR}

.ifndef NOPORTDOCS
SUB_FILES+=		install.txt
.endif

WRKSRC=			${WRKDIR}/${PORTNAME}_2.0

WWW_DIR?=		${PREFIX}/www/data
WITH_TF_HTMLDIR?=	${WWW_DIR}/tf
WITH_TF_DATADIR?=	${DATADIR}/data
WITH_TF_DBDIR?=		${WITH_TF_DATADIR}/.database

post-extract:
	@${CP} -f ${FILESDIR}/overlib.js ${WRKSRC}/html
	@cd ${WRKSRC} && ${FIND} -E html \
		-type f -regex '.*\.(php|css|js)' -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD} -e 's/$$//'

do-build:
	@${REINPLACE_CMD} \
		-e 's;%%PREFIX%%;${PREFIX};g' \
		-e 's;%%DATADIR%%;${DATADIR};g' \
		-e 's;%%LOCALBASE%%;${LOCALBASE};g' \
		-e 's;%%DOWNLOADS%%;${WITH_TF_DATADIR};g' \
		-e 's;%%DATABASE%%;${WITH_TF_DBDIR};g' \
		-e 's;%%PORTVERSION%%;${DISTVERSION}-${OPSYS}${OSREL};g' \
		-e "s;^include_once([\"']config.php['\"]);include_once(\"${PREFIX}/etc/tfconfig.php\");" \
		${WRKSRC}/html/*.php
	@${REINPLACE_CMD} -e '1s;/usr/bin/env python;${PYTHON_CMD};' \
		${WRKSRC}/TF_BitTornado/btphptornado.py

do-install:
	@cd ${WRKSRC}/html \
	&& ${INSTALL_DATA} config.php ${PREFIX}/etc/tfconfig.php.default \
	&& ${FIND} -E . \
		-path './adodb' -prune  \
		-o -type d -exec ${MKDIR} ${WITH_TF_HTMLDIR}/{} \; \
		-o -path './config.php' \
		-o -regex '.*\.(php|css|js|html|gif|png|ico|htaccess)' \
			-exec ${INSTALL_DATA} {} ${WITH_TF_HTMLDIR}/{} \;
	@${INSTALL_SCRIPT} ${WRKSRC}/TF_BitTornado/btphptornado.py ${PREFIX}/libexec/
	@${INSTALL_SCRIPT} ${WRKDIR}/torrentflux.sh ${PREFIX}/etc/rc.d/
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${FILESDIR}/torrentflux.sqlite ${DATADIR}/
	@[ -f ${PREFIX}/etc/tfconfig.php ] \
		|| ${CP} ${PREFIX}/etc/tfconfig.php.default ${PREFIX}/etc/tfconfig.php
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/install.txt ${DOCSDIR}/
.endif

post-install:
	@cd ${PREFIX} && ${FIND} -d ${WITH_TF_HTMLDIR:S;^${PREFIX}/;;} \
		-type f -print -o -type d -exec echo "@dirrm {}" \; \
		>>${TMPPLIST}
	@if [ -f "${PKGINSTALL}" ]; then \
		${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" \
			${SH} "${PKGINSTALL}" ${PKGNAME} POST-INSTALL; \
	fi
	@if [ -f "${PKGMESSAGE}" ]; then \
		${CAT} "${PKGMESSAGE}"; \
	fi

.include <bsd.port.mk>

# This is evil! If you happen to hate this hack, just delete these lines.
# OTOH, DATADIR is defined in bsd.port.post.mk, so it won't work earlier
# (we do not benefit from delayed evaluation in ".if"-lines).
.if ${WITH_TF_DATADIR:S"^${DATADIR}/""} == data
pre-everything::
	@${ECHO} "==============================================="
	@${ECHO}
	@${ECHO} "You might want to customize WITH_TF_DATADIR,"
	@${ECHO} "it should reside on a partition with enough"
	@${ECHO} "free space for all files you plan to download."
	@${ECHO}
	@${ECHO} "NOTE: Do not place it under your webroot."
	@${ECHO}
	@${ECHO} "==============================================="
.endif
