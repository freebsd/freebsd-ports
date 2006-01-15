# New ports collection makefile for:	iwebcal
# Date created:		2006-01-14
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	iwebcal
PORTVERSION=	2.0.b4
CATEGORIES=	www deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2.0b4
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	Webbased iCal calendar viewer

NO_BUILD=	yes
USE_PHP=	yes
IWEBCAL=	www/iwebcal
WWWDIR=		${PREFIX}/${IWEBCAL}
WRKSRC=		${WRKDIR}/iWebCal
PLIST_SUB=	IWEBCAL=${IWEBCAL}

post-extract:
	-@${FIND} ${WRKSRC}/ -type d -name '.svn' | ${XARGS} ${RM} -rf

do-install:
.if !exists(${WWWDIR})
	${MKDIR} ${WWWDIR}
.endif
	@${CP} -R ${WRKSRC}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

.include <bsd.port.mk>
