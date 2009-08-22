# New ports collection makefile for:	phpbb3
# Date created:		20 Dec 2007
# Whom:	      		Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	3.0.5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/phpBB%203/phpBB%20${PORTVERSION}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	A PHP-based bulletin board / discussion forum system

CONFLICTS=	phpbb-tw-[0-9]* phpbb-devel-[0-9]* \
		phpbb-[0-2]*

USE_BZIP2=	yes

# The phpBB2 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www
PHPBBURL?=	phpBB3
#
# End of user-configurable variables.

LATEST_LINK?=	phpbb3
WRKSRC=		${WRKDIR}/phpBB3
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}"

PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts

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
