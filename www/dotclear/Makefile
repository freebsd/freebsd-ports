# New ports collection makefile for:	www/dotclear
# Date created:		2008-12-28
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotclear
PORTVERSION=	2.1.6
CATEGORIES=	www
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A state-of-the-art semantic personal publishing platform

NO_BUILD=	yes
USE_PHP=	mysql xml simplexml mbstring iconv gd
USE_MYSQL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}
	${TOUCH} ${WWWDIR}/inc/config.php
	@${CHOWN} ${WWWOWN} ${WWWDIR}/inc/config.php
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/inc/config.php;chown ${WWWOWN} %D/%%WWWDIR%%/inc/config.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/inc/config.php ];then rm -f %D/%%WWWDIR%%/inc/config.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
