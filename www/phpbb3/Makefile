# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	phpbb
PORTVERSION=	3.0.11
CATEGORIES=	www
MASTER_SITES=	https://www.phpbb.com/files/release/
DISTNAME=	phpBB-${PORTVERSION}
PKGNAMESUFFIX=	3

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	A PHP-based bulletin board / discussion forum system

LICENSE=	GPLv2

CONFLICTS=	phpbb-tw-[0-9]* phpbb-devel-[0-9]* \
		phpbb-[0-2]*

USE_BZIP2=	yes
USE_PHP=	yes

# The phpBB3 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www
PHPBBURL?=	phpBB3
#
# End of user-configurable variables.

WRKSRC=		${WRKDIR}/phpBB3
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}"

PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

NO_STAGE=	yes
# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
PORTDOCS=	*

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

do-install:
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${PHPBBDIR} "! -name config.php"
	@ [ -f ${PREFIX}/${PHPBBDIR}/config.php ] || ${TOUCH} ${PREFIX}/${PHPBBDIR}/config.php
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}
	@ ${CHMOD} -R 0755 ${PREFIX}/${PHPBBDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${PHPBBDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.mk>
