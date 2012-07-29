# New ports collection makefile for:	open79xxdir
# Date created:		16 FEB 2006
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	openxmldir
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	SF/open79xxdir/OpenXMLDir/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based XML menuing system for Cisco 79xx IP phones

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_PHP=	mysql xml
PLIST_SUB+=	OPENXMLDIR=${OPENXMLDIR}
OPENXMLDIR=	www/${PORTNAME}

do-install:
	-${MKDIR} ${PREFIX}/${OPENXMLDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${OPENXMLDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${OPENXMLDIR}
	@${CHMOD} 755 ${PREFIX}/${OPENXMLDIR}

.include <bsd.port.mk>
