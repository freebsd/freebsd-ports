# New ports collection makefile for: WackoWikki
# Date created:		05.Dec 2004
# Whom:			Ivan Sviridov (sin@vimcom.net)
# $FreeBSD$

PORTNAME=	wacko
PORTVERSION=	4
CATEGORIES=	www
MASTER_SITES=	http://wackowiki.com/files/
DISTNAME=	wacko.r4

MAINTAINER=	sin@vimcom.net
COMMENT=	A small and fast PHP Wikki clone with 30+ languages support

USE_BZIP2=	yes
# The  port supports a number of variables that may be tweaked at build
# time.
#
WWWDOCROOT?=	www/data
WACKOURL?=	wacko
WWWOWN?=	www
WWWGRP?=	www
#
# End of user-configurable variables.
CFGFILE=interwiki.conf
# Set/override/append to variables from bsd.port.mk:
#

WRKSRC=		${WRKDIR}/${PORTNAME}
WACKODIR=	${WWWDOCROOT}/${WACKOURL}
NO_BUILD=	yes
USE_PHP=	mysql session
PLIST_SUB+=	WACKODIR="${WACKODIR}"

do-extract:
	@ ${MKDIR} ${WRKSRC}
	@ cd ${WRKSRC} && ${EXTRACT_CMD}  ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

post-patch:
	@ ${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample

do-install:
	@ ${MKDIR}  ${PREFIX}/${WACKODIR}
	@ ${CP} -R ${WRKSRC}/ ${PREFIX}/${WACKODIR}
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WACKODIR}

post-install:
	@ ${ECHO_MSG} ""
	@ ${ECHO_MSG} " GoTo: http://<your_website>/${WACKOURL}"
	@ ${ECHO_MSG} ""

.include <bsd.port.mk>
