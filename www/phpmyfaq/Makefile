# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	1.6.1
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	${PORTNAME}.${PORTVERSION}.full
EXTRACT_SUFX=	.zip

MAINTAINER=	babak@farrokhi.net
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}
USE_ZIP=	YES

USE_PHP=	mysql pcre pdf session xml xmlrpc zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

pre-fetch:
.if !defined(PHPMYFAQ_URL)
	 @${ECHO_MSG} ""
	 @${ECHO_MSG} "Define PHPMYFAQ_URL to override default of ${PREFIX}/'${PHPMYFAQ_URL}'."
	 @${ECHO_MSG} ""
.endif

# Get HOSTNAME
.if exists(/sbin/sysctl)
HOSTNAME!=	/sbin/sysctl -n kern.hostname
.else
HOSTNAME!=	/usr/sbin/sysctl -n kern.hostname
.endif

WWWDOCROOT?=	www/data
PHPMYFAQ_URL?=	${WWWDOCROOT}/faq
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKSRC} && ${FIND} -s . \( ! -path "*CVS*" -and -type f \) | \
		${SED} -e 's|^./||;s|^|${PHPMYFAQ_URL}/|' > ${PLIST} \
		&& ${FIND} -d * \( ! -path "*CVS*" -and -type d \) | \
		${SED} -e 's|^|@dirrm ${PHPMYFAQ_URL}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_URL}/attachments/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_URL}/data/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_URL}/pdf/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_URL}/xml/ >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PHPMYFAQ_URL} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry ${WWWDOCROOT} >> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${PHPMYFAQ_URL}
	@${CHMOD} 755 ${PREFIX}/${PHPMYFAQ_URL}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMYFAQ_URL}
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_URL}/attachments/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_URL}/data/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_URL}/pdf/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ_URL}/xml/
	# set the correct permissions
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/inc/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/attachments/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/data/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/images/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/pdf/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ_URL}/xml/
	@${FIND} ${PREFIX}/${PHPMYFAQ_URL} \( -type f -and -path "*CVS*" \) | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/${PHPMYFAQ_URL} \( -type d -and -path "*CVS*" \) | ${XARGS} ${RM} -r
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMYFAQ_URL}

post-install:
	@${SED} \
	 -e 's|%%HOSTNAME%%|${HOSTNAME}|' \
	 -e 's|%%PHPMYFAQ_URL%%|${PREFIX}/${PHPMYFAQ_URL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
