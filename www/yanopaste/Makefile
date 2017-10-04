# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yanopaste
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Nopaste

NO_BUILD=	yes
USES+=		php
USE_PHP=	xsl session xmlwriter xmlreader
SUB_FILES=	pkg-message

post-patch:
	${FIND} ${WRKSRC} -name .svn -type d | ${XARGS} ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/config.php;chown ${WWWOWN} %D/%%WWWDIR%%/config.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/config.php ];then rm -f %D/%%WWWDIR%%/config.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d -empty \
	| ${SED} -e 's,^${WRKSRC},@dir %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
