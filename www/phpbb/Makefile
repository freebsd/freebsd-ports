# New ports collection makefile for:	phpBB
# Date created:		25 April 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	2.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/php/System.php:${PORTSDIR}/www/mod_php4

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
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

# Set custom variables:
#
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
PKGOPTS=	${FILESDIR}/pkg-opts
EXCEPTFILES=	install.php upgrade.php update_to_${PORTVERSION:S/.//g}.php

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

post-extract:
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${REINPLACE_CMD} -e "s#\.\./templates#/${PHPBBURL}/templates#" \
	  ${WRKSRC}/docs/*.html

post-configure:
	@ ${SED} \
	  -e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%DOCSDIR%%#${DOCSDIR}#g' \
	  -e 's#%%PHPBBURL%%#${PHPBBURL}#g' -e 's#%%PHPBBDIR%%#${PHPBBDIR}#g' \
	  -e 's#%%DATADIR%%#${DATADIR}#g' \
	  -e 's#%%DELETEFILES%%#${EXCEPTFILES}#g' pkg-message > ${PKGMESSAGE}

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
	@ cd ${DATADIR} && ${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
	  ${EXCEPTFILES} ${PREFIX}/${PHPBBDIR}
.if !defined(NOPORTOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC}/docs && ${FIND} * -type f -maxdepth 0 \! -name \*.bak \
	  \! -name COPYING -exec ${INSTALL_DATA} {} ${DOCSDIR} \;
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.mk>
