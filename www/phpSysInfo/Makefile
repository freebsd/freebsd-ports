# New ports collection makefile for:	phpSysInfo
# Date created:				Mon Mar 04, 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$

PORTNAME=	phpSysInfo
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	so14k@so14k.com
COMMENT=	A php script that displays info about the host being accessed

USE_PHP=	pcre xml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:L}-dev
WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${PREFIX}/www/data
INSTALLDIR=	${APACHEDIR}/phpSysInfo
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

PLIST_SUB=	INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

post-patch:
	${RM} -f ${PLIST}
	cd ${WRKSRC};\
	${FIND} . ! -type d | ${SORT} | ${SED} "s|^.|%%INSTALLDIR%%|"\
		>${PLIST};\
	${FIND} . -type d | ${SORT} -r | ${SED} "s|^.|@dirrm %%INSTALLDIR%%|"\
		>>${PLIST}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
	${CHMOD} -R ${BINMODE} ${INSTALLDIR}
	${FIND} ${INSTALLDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>
