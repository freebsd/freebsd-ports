# New ports collection makefile for:	textpattern
# Date created:		30 Nov 2005
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	textpattern
PORTVERSION=	4.0.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://textpattern.com/file_download/37/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A free, flexible, elegant, easy-to-use content management system

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_PHP=	mbstring xml mysql pcre

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
