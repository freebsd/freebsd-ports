# New ports collection makefile for:	phpBB
# Date created:		25 April 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/php/System.php:${PORTSDIR}/www/mod_php4

# The phpBB2 port supports a number of variables that may be tweaked at build
# time.  Perform a "make options" to see more information on these variables.
#
WRKSRC=		${WRKDIR}/phpBB2
NO_BUILD=	yes
CPIO=		cpio --quiet -pdum -R
WWWDOCROOT=	www/data
PHPBBURL=	phpBB2
PHPBBDIR=	${WWWDOCROOT}/${PHPBBURL}
WWWOWN=		www
WWWGRP=		www
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGOPTS=	${FILESDIR}/pkg-opts
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR} WWWOWN=${WWWOWN}
EXCEPTFILES=	install.php upgrade.php update_to_FINAL.php

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${PERL} -ne '/^#/ || /^\s/ && print || \
	  print sprintf "* %s [%s]\n  %s", split(/\|/)' ${PKGOPTS}

post-extract:
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	  (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	   ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	   ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${PERL} -pi.orig -e "s#\.\./templates#/${PHPBBURL}/templates#" \
	  ${WRKSRC}/docs/*.html

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
	  -e 's#%%DOCSDIR%%#${DOCSDIR}#g' \
	  -e 's#%%PHPBBURL%%#${PHPBBURL}#g' \
	  -e 's#%%PHPBBDIR%%#${PHPBBDIR}#g' pkg-message > \
	  ${PKGMESSAGE}

do-install:
	@ ${MKDIR} -m 0775 ${PREFIX}/${PHPBBDIR}
	@ ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}
	@ cd ${WRKSRC} && find * \( -name config.php \
	  ${EXCEPTFILES:S/^/-o -name /} -o -name docs -a -prune \) \
	  -o -print | ${CPIO} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}
	@ ${TOUCH} ${PREFIX}/${PHPBBDIR}/config.php
	@ ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}/config.php
	@ ${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${EXCEPTFILES} ${DATADIR}

post-install:
	@ cd ${DATADIR} && ${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
	  ${EXCEPTFILES} ${PREFIX}/${PHPBBDIR}
.if !defined(NOPORTOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in AUTHORS FAQ.html INSTALL.html README.html \
                coding-guidelines.txt codingstandards.htm
	@ ${INSTALL_DATA} ${WRKSRC}/docs/${docfile} ${DOCSDIR}
.endfor
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.mk>
