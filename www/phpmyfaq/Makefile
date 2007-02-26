# New ports collection makefile for:	phpmyfaq
# Date created:		2005-04-15
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	phpmyfaq
PORTVERSION=	1.6.10
CATEGORIES=	www
MASTER_SITES=	http://www.phpmyfaq.de/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}.full

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A multilingual, completely database-driven FAQ-system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PHP=	mysql pcre pdf session xml xmlrpc zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

pre-everything::
.if !defined(PHPMYFAQ)
	 @${ECHO_MSG} ""
	 @${ECHO_MSG} "Define PHPMYFAQ to override default installation place of '${PREFIX}/${PHPMYFAQ}'."
	 @${ECHO_MSG} ""
.endif

PHPMYFAQ?=	www/${PORTNAME}
PLIST_SUB+=	PHPMYFAQ=${PHPMYFAQ}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${PHPMYFAQ}
	@${CHMOD} 755 ${PREFIX}/${PHPMYFAQ}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMYFAQ}
	@${MKDIR} ${PREFIX}/${PHPMYFAQ}/attachments/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ}/data/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ}/pdf/
	@${MKDIR} ${PREFIX}/${PHPMYFAQ}/xml/
	# set the correct permissions
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/inc/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/attachments/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/data/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/images/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/pdf/
	@${CHMOD} 777 ${PREFIX}/${PHPMYFAQ}/xml/
	@${FIND} ${PREFIX}/${PHPMYFAQ} \( -type f -and -path "*CVS*" \) | ${XARGS} ${RM}
	@${FIND} ${PREFIX}/${PHPMYFAQ} \( -type d -and -path "*CVS*" \) | ${XARGS} ${RM} -r
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMYFAQ}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
