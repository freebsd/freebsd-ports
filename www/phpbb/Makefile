# New ports collection makefile for:	phpBB
# Date created:		25 April 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpbb
PORTVERSION=	2.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	phpBB-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

WRKSRC=		${WRKDIR}/phpBB2
NO_BUILD=	yes
CPIO=		cpio --quiet -pdum -R
PHPBBDIR=	www/data/phpBB
WWWOWN=		www
WWWGRP=		www
PLIST_SUB+=	PHPBBDIR=${PHPBBDIR}

do-install:
	@ ${MKDIR} -m 0775 ${PREFIX}/${PHPBBDIR} && \
	  ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPBBDIR}
	@ cd ${WRKSRC} && find * | ${CPIO} ${WWWOWN}:${WWWGRP} \
	  ${PREFIX}/${PHPBBDIR}

.include <bsd.port.mk>
