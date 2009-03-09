# New ports collection makefile for:	textpattern
# Date created:		30 Nov 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	textpattern
PORTVERSION=	4.0.8
CATEGORIES=	www
MASTER_SITES=	http://textpattern.com/file_download/52/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A free, flexible, elegant, easy-to-use content management system

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_PHP=	mbstring xml mysql pcre
WRKSRC=		${WRKDIR}/${PORTNAME}-4.0.5/

SUB_FILES=	pkg-message

do-install:
	-${MKDIR} ${WWWDIR}
	@${CP} -R ${WRKSRC}/ ${WWWDIR}/
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
	| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
