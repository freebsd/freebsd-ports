# New ports collection makefile for:	phpbb-devel
# Date created:		1 Jun 2007
# Whom:	      		Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	3.0r2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpbb
PKGNAMESUFFIX=	-devel
DISTNAME=	phpBB-3.0.RC2

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	A PHP-based bulletin board / discussion forum system

CONFLICTS=	phpbb-tw-[0-9]* phpbb-[0-9]*

USE_BZIP2=	yes

# The phpBB2 port supports a number of variables that may be tweaked at build
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
		PHPBBDIR="${PHPBBDIR}" \

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
	@ ${MKDIR} -m 0775 ${PREFIX}/${PHPBBDIR}
	@ cd ${WRKSRC} && ${FIND} . -print | ${TAR} cTf - - | ${TAR} xUCf ${PREFIX}/${PHPBBDIR} -
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${FIND} . -print | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.mk>
