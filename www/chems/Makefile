# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chems
DISTVERSION=	0x04
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0x04

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	The geekest content helper management system

NO_BUILD=	yes
USES=		zip
USE_PHP=	xml iconv gd
SUB_FILES=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/usr/config.php
	@${CHOWN} ${WWWOWN} ${STAGEDIR}${WWWDIR}/usr/config.php

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/usr/config.php;chown ${WWWOWN} %D/%%WWWDIR%%/usr/config.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/usr/config.php ];then rm -f %D/%%WWWDIR%%/usr/config.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
