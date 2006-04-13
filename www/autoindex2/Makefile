# New ports collection makefile for:	AutoIndex
# Date created:				17 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	AutoIndex
PORTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	autoindex

MAINTAINER=	danger@rulez.sk
COMMENT=	PHP 5.x script that makes a table that lists the files in a directory

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	session
DEFAULT_PHP_VER=	5
BROKEN_WITH_PHP=	4
CONFLICTS=	AutoIndex-1*
LATEST_LINK=	AutoIndex2
NO_BUILD=	yes

PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

pre-fetch:
.if !defined(INSTALLDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define INSTALLDIR to override default of 'www/data/${PORTNAME}'."
	@${ECHO_MSG} ""
.endif

INSTALLDIR?=	www/data/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALLDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${INSTALLDIR}
	@${CP} -p ${WRKSRC}/.htpasswd.autoindex ${PREFIX}/${INSTALLDIR}/.htpasswd.autoindex-dist
	@${CHMOD} 666 ${PREFIX}/${INSTALLDIR}/config.php
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
