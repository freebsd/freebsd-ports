# New ports collection makefile for:	phpSysInfo
# Date created:				Mon Mar 04, 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$

PORTNAME=	phpSysInfo
PORTVERSION=	2.5.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	A php script that displays info about the host being accessed

USE_PHP=	pcre xml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:L}
WWWOWN?=	www
WWWGRP?=	www
WWWDIR?=	www/${PORTNAME}
DATADIR=	${PREFIX}/${WWWDIR}
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

post-patch:
	${RM} -f ${PLIST}
	cd ${WRKSRC};\
	${FIND} . ! -type d | ${SORT} | ${SED} "s|^\.|${WWWDIR}|"\
		>${PLIST};\
	${FIND} . -type d | ${SORT} -r | ${SED} "s|^\.|@dirrm ${WWWDIR}|"\
		>>${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	${CHMOD} -R ${BINMODE} ${DATADIR}
	${FIND} ${DATADIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>
