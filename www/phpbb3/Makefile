# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	phpbb
PORTVERSION=	3.0.11
CATEGORIES=	www
MASTER_SITES=	https://www.phpbb.com/files/release/
DISTNAME=	phpBB-${PORTVERSION}
PKGNAMESUFFIX=	3

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	PHP-based bulletin board / discussion forum system

LICENSE=	GPLv2

CONFLICTS=	phpbb-tw-[0-9]* phpbb-devel-[0-9]* \
		phpbb-[0-2]*

USES=		tar:bzip2
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
	@ cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PHPBBDIR} "! -name config.php"
	@ ${TOUCH} ${STAGEDIR}${PREFIX}/${PHPBBDIR}/config.php.sample
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${PHPBBDIR}
	@ ${CHMOD} -R 0755 ${STAGEDIR}${PREFIX}/${PHPBBDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${PHPBBDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}

post-install:
	@ ${MKDIR} ${STAGEDIR}${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
