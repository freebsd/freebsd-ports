# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	1.4.8
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}.full
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.full/${PORTNAME}.${PORTVERSION}
USE_ZIP=	YES

USE_PHP=	mysql pcre session
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

WWWDOCROOT?=	www/data
PHPMYFAQURL?=	faq
WWWOWN?=	www
WWWGRP?=	www

PHPMYFAQDIR?=	${WWWDOCROOT}/${PHPMYFAQURL}
PLIST=		${WRKDIR}/pkg-plist
EXCEPTFILES=	${PREFIX}/${PHPMYFAQDIR}/install/bbcode2xhtml.php \
		${PREFIX}/${PHPMYFAQDIR}/install/index.html \
		${PREFIX}/${PHPMYFAQDIR}/install/installer.php \
		${PREFIX}/${PHPMYFAQDIR}/install/update.php

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKSRC} && ${MV} inc/data.php.original inc/data.php \
		&&  ${MV} inc/config.php.original inc/config.php \
		&& ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${PHPMYFAQDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${PHPMYFAQDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQDIR}/attachment/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQDIR}/data/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQDIR}/pdf/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQDIR} >> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${PHPMYFAQDIR}
	@${CHOWN} www:www ${PREFIX}/${PHPMYFAQDIR}
	@${CHMOD} 755 ${PREFIX}/${PHPMYFAQDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMYFAQDIR}
	@${MKDIR} ${PREFIX}/${PHPMYFAQDIR}/attachment/
	@${MKDIR} ${PREFIX}/${PHPMYFAQDIR}/data/
	@${MKDIR} ${PREFIX}/${PHPMYFAQDIR}/pdf/
	#set the correct permissions
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/inc/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/attachment/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/data/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/images/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/pdf/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQDIR}/xml/

post-install:
	@${SED} \
	 -e 's|%%DELETEFILES%%|${EXCEPTFILES}|' \
	 -e 's|%%PHPMYFAQURL%%|${PHPMYFAQURL}|' \
	 -e 's|%%PHPMYFAQDIR%%|${PREFIX}/${PHPMYFAQDIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
