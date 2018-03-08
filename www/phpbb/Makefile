# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpbb
PORTVERSION=	2.0.23
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/phpBB%202/phpBB%20v${PORTVERSION}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	liukang@cn.freebsd.org
COMMENT=	PHP-based bulletin board / discussion forum system

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear@${PHP_FLAVOR}

CONFLICTS=	phpbb-tw-[0-9]*

USES=		tar:bzip2 php

# The phpBB2 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www
PHPBBURL?=	phpBB2
#
# End of user-configurable variables.

# Set/override/append to variables from bsd.port.mk:
#
WRKSRC=		${WRKDIR}/phpBB2
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}" \
		DELETEFILES="${EXCEPTFILES:S,${STAGEDIR},,g}"
PHPBB_VER=	${PORTVERSION:S/.//g:S/.//g}
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB+=	PHPBB_VER=${PHPBB_VER}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
EXCEPTFILES=	${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/install.php \
		${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/upgrade.php \
		${STAGEDIR}${PREFIX}/${PHPBBDIR}/install/update_to_latest.php

OPTIONS_DEFINE=	DOCS

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${REINPLACE_CMD} -e "s#\.\./templates#/${PHPBBURL}/templates#" \
	  ${WRKSRC}/docs/*.html
	@${FIND} ${WRKSRC} -name '*.orig' -or -name '*.bak' -delete

do-install:
	@${MKDIR} -m 0775 ${STAGEDIR}${PREFIX}/${PHPBBDIR}
	@cd ${WRKSRC} && ${FIND} * \( -name config.php \
	  ${EXCEPTFILES:S/^/-o -name /} \
	  -o -name docs -a -prune -o -name contrib -a -prune \) -o -print \
	  | ${TAR} cTf - - | ${TAR} xUCf ${STAGEDIR}${PREFIX}/${PHPBBDIR} -
	@${INSTALL_DATA} ${WRKSRC}/config.php ${STAGEDIR}${PREFIX}/${PHPBBDIR}/config.php.example
	@${MKDIR} ${STAGEDIR}${DATADIR}/contrib
	@cd ${WRKSRC} && ${INSTALL_DATA} ${EXCEPTFILES} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/contrib && ${INSTALL_DATA} * ${STAGEDIR}${DATADIR}/contrib
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} * -type f -maxdepth 0 \
	  \! -name COPYING -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;

.include <bsd.port.mk>
