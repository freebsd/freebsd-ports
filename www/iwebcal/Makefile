# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	iwebcal
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	www deskutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webbased iCal calendar viewer

EXPIRATION_DATE=	2018-03-07
DEPRECATED=	Unmaintained, all www files wrongly belongs to www user.

USES=		php tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/iWebCal
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

post-extract:
	-@${FIND} ${WRKSRC}/ -type d -name '.svn' | ${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
