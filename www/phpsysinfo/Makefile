# New ports collection makefile for:	phpSysInfo
# Date created:				Mon Mar 04, 2002
# Whom:					Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$

PORTNAME=	phpSysInfo
PORTVERSION=	2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpsysinfo

MAINTAINER=	so14k@so14k.com
COMMENT=	A php script that displays info about the host being accessed

WANT_PHP_WEB=	yes

PREFIX=		${LOCALBASE}
WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${PREFIX}/www/data
INSTALLDIR=	${APACHEDIR}/phpSysInfo
NO_BUILD=	yes
PLIST=		${WRKDIR}/plist

PLIST_SUB+=	INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/php4/bsd.php.mk"

post-patch:
	rm -f ${PLIST}
	cd ${WRKSRC};\
	${FIND} . ! -type d | sort | ${SED} "s|^.|%%INSTALLDIR%%|"\
		>${PLIST};\
	${FIND} . -type d | sort -r | ${SED} "s|^.|@dirrm %%INSTALLDIR%%|"\
		>>${PLIST}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| cpio -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
	${CHMOD} -R ${BINMODE} ${INSTALLDIR}
	${FIND} ${INSTALLDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.post.mk>
