# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dotclear
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	State-of-the-art semantic personal publishing platform

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		cpe
NO_BUILD=	yes
USE_PHP=	mysql xml simplexml mbstring iconv gd
USE_MYSQL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/inc/config.php.sample

create-plist:
	@${FIND} -s ${WRKSRC}/ -not -type d \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) %%WWWDIR%%/inc/config.php.sample' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/ -type d -empty \
		| ${SED} -e 's,^${WRKSRC},@dir %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
