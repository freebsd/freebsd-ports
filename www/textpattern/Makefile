# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	textpattern
PORTVERSION=	4.2.0
CATEGORIES=	www
MASTER_SITES=	http://textpattern.com/file_download/57/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, flexible, elegant, easy-to-use content management system

USES=		cpe
NO_BUILD=	yes
WANT_PHP_WEB=	yes
USE_PHP=	mbstring xml mysql pcre

SUB_FILES=	pkg-message

do-install:
	-${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
	| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
