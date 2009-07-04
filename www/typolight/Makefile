# New ports collection makefile for:	typolight
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	typolight
PORTVERSION=	2.7.2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Powerful web content management system

NO_BUILD=	yes
USE_PHP=	xsl mysql iconv gd
USE_MYSQL=	yes
SUB_FILES=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}
	${TOUCH} ${WWWDIR}/system/config/localconfig.php
	@${CHOWN} ${WWWOWN} ${WWWDIR}/system/config/localconfig.php
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/system/config/localconfig.php;chown ${WWWOWN} %D/%%WWWDIR%%/system/config/localconfig.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/system/config/localconfig.php ];then rm -f %D/%%WWWDIR%%/system/config/localconfig.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
