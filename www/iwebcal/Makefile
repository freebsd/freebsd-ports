# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	iwebcal
PORTVERSION=	2.1
CATEGORIES=	www deskutils
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webbased iCal calendar viewer

NO_BUILD=	yes
USE_PHP=	yes
WRKSRC=		${WRKDIR}/iWebCal

NO_STAGE=	yes
post-extract:
	-@${FIND} ${WRKSRC}/ -type d -name '.svn' | ${XARGS} ${RM} -rf

do-install:
.if !exists(${WWWDIR})
	${MKDIR} ${WWWDIR}
.endif
	@${CP} -R ${WRKSRC}/* ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

.include <bsd.port.mk>
