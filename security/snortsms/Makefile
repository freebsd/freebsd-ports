# New ports collection makefile for:	snortsms
# Date created:		Mon May 28 16:05:01 CST 2005
# Whom:			J Randolph <snortsms@servangle.net>
#
# $FreeBSD$
#

PORTNAME=	snortsms
PORTVERSION=	1.2.2
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	snortsms

MAINTAINER=	snortsms@servangle.dnydns.org
COMMENT=	A remote management and monitoring interface for Snort based IDS

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB \
		${LOCALBASE}/bin/curl:${PORTSDIR}/ftp/curl

USE_PHP=	mysql pcre pcntl session
NO_BUILD=	yes

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
# Create directory structure
	@${MKDIR} ${PREFIX}/www/snortsms
# copy files
	${CP} -R ${WRKSRC}/* ${PREFIX}/www/snortsms
	${RM} ${PREFIX}/www/snortsms/COPYING
# correct permissions
	${CHMOD} 775 ${PREFIX}/www/snortsms/conf
	${CHOWN} :${WWWGRP} ${PREFIX}/www/snortsms/conf

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
