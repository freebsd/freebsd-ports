# New ports collection makefile for:	phpBB
# Date created:		25 April 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	2.0.17
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	liukang@bjut.edu.cn
COMMENT=	A PHP-based bulletin board / discussion forum system

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear-PEAR

USE_BZIP2=	yes

# The phpBB2 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WWWDOCROOT?=	www/data
PHPBBURL?=	phpBB2
WWWOWN?=	www
WWWGRP?=	www
#
# End of user-configurable variables.

# Set/override/append to variables from bsd.port.mk:
#
WRKSRC=		${WRKDIR}/phpBB2
NO_BUILD=	yes
USE_REINPLACE=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPBBURL="${PHPBBURL}" \
		PHPBBDIR="${PHPBBDIR}" \
		DELETEFILES="${EXCEPTFILES}"
PHPBB_VER=	${PORTVERSION:S/.//g:S/.//g}
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB+=	PHPBB_VER=${PHPBB_VER}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
EXCEPTFILES=	${PREFIX}/${PHPBBDIR}/install/install.php \
		${PREFIX}/${PHPBBDIR}/install/upgrade.php \
		${PREFIX}/${PHPBBDIR}/install/update_to_latest.php

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
	@${RM} -f `${FIND} ${WRKSRC} -name '*.orig'`

do-install:
	@ ${MKDIR} -m 0775 ${PREFIX}/${PHPBBDIR}
	@ cd ${WRKSRC} && ${FIND} * \( -name config.php \
	  ${EXCEPTFILES:S/^/-o -name /} \
	  -o -name docs -a -prune -o -name contrib -a -prune \) -o -print \
	  | ${TAR} cTf - - | ${TAR} xUCf ${PREFIX}/${PHPBBDIR} -
	@ ${TOUCH} ${PREFIX}/${PHPBBDIR}/config.php
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}
	@ ${MKDIR} ${DATADIR}/contrib
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${EXCEPTFILES} ${DATADIR}
	@ cd ${WRKSRC}/contrib && ${INSTALL_DATA} * ${DATADIR}/contrib

post-install:
#	@ cd ${DATADIR} && ${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
#	  ${EXCEPTFILES} ${PREFIX}/${PHPBBDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${FIND} * -type f -maxdepth 0 \! -name \*.bak \
	  \! -name COPYING -exec ${INSTALL_DATA} {} ${DOCSDIR} \;
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.mk>
