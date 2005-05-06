# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wikipedia

MAINTAINER=	tux@pinguru.net
COMMENT=	The wiki enginge used by Wikipedia

CONFLICTS=	mediawiki-1.3.*

NO_BUILD=	yes
USE_PHP=	mysql session zlib
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/data-dist/mediawiki

do-install:
	-${MKDIR} ${PREFIX}/${MEDIAWIKIDIR}
	@${CP} -r ${WRKSRC}/ ${PREFIX}/${MEDIAWIKIDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MEDIAWIKIDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${SED} -e 's|%%MEDIAWIKIDIR%%|${PREFIX}/${MEDIAWIKIDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
