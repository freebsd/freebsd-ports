# New ports collection makefile for:	yanopaste
# Date created:		2008-09-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yanopaste
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Yet Another Nopaste

NO_BUILD=	yes
USE_PHP=	xsl
SUB_FILES=	pkg-message
WWWDIR?=	${PREFIX}/www/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC} -name .svn -type d | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}
	@${TOUCH} ${WWWDIR}/config.php
	@${CHOWN} ${WWWOWN} ${WWWDIR}/config.php
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/config.php;chown ${WWWOWN} %D/%%WWWDIR%%/config.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/config.php ];then rm -f %D/%%WWWDIR%%/config.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
