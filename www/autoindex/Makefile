# New ports collection makefile for:	AutoIndex
# Date created:				17 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	AutoIndex
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}%20PHP%20Script%201.x/${PORTNAME}%20PHP%20${PORTVERSION}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	PHP 4.x script that makes a table that lists the files in a directory

WRKSRC=		${WRKDIR}/${PORTNAME}

IGNORE_WITH_PHP=	5
USE_PHP=	session
CONFLICTS=	AutoIndex-2*
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
	@${CP} -Rp ${WRKSRC}/* ${PREFIX}/${INSTALLDIR}
	@${CP} -p ${WRKSRC}/.htpasswd.autoindex ${PREFIX}/${INSTALLDIR}/.htpasswd.autoindex-dist
	@${CHMOD} 666 ${PREFIX}/${INSTALLDIR}/config.php
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
