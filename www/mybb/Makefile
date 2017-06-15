# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mybb
PORTVERSION=	1.8.10
CATEGORIES=	www

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHP-based bulletin board / discussion forum system

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_TAGNAME=	${PORTNAME}_1810

USES=		cpe mysql php
NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	xsl mysql iconv gd xml
SUB_FILES=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/inc/config.php.sample
	${MV} ${STAGEDIR}${WWWDIR}/inc/settings.php \
		${STAGEDIR}${WWWDIR}/inc/settings.php.sample

.include <bsd.port.mk>
