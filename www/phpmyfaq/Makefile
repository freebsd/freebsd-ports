# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	1.4.9
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}.full
EXTRACT_SUFX=	.zip

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A multilingual, completely database-driven FAQ-system

FORBIDDEN=	http://vuxml.FreeBSD.org/e65ad1bf-0d8b-11da-90d0-00304823c0d3.html

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}
USE_ZIP=	YES

USE_PHP=	mysql pcre pdf session xml xmlrpc zlib
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

pre-fetch:
.if !defined(PHPMYFAQ_DIR)
	 @${ECHO_MSG} ""
	 @${ECHO_MSG} "Define PHPMYFAQ_DIR to override default of '${PHPMYFAQ_DIR}'."
	 @${ECHO_MSG} ""
.endif

WWWDOCROOT?=	www/data
PHPMYFAQ_URL?=	faq
WWWOWN?=	www
WWWGRP?=	www
PHPMYFAQ_DIR?=	${WWWDOCROOT}/${PHPMYFAQ_URL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${PHPMYFAQ_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${PHPMYFAQ_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_DIR}/attachments/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_DIR}/data/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_DIR}/pdf/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_DIR} >> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${PHPMYFAQ_DIR}
	@${CHMOD} 755 ${PREFIX}/${PHPMYFAQ_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMYFAQ_DIR}
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_DIR}/attachments/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_DIR}/data/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_DIR}/pdf/
	# set the correct permissions
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/inc/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/attachments/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/data/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/images/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/pdf/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_DIR}/xml/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMYFAQ_DIR}

post-install:
	@${SED} \
	 -e 's|%%PHPMYFAQ_URL%%|${PHPMYFAQ_URL}|' \
	 -e 's|%%PHPMYFAQ_DIR%%|${PREFIX}/${PHPMYFAQ_DIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
