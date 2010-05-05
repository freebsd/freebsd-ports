# New ports collection makefile for: repos-style
# Date created:		12 Aug 2009
# Whom:			Alexander Kriventsov
#
# $FreeBSD$
#

PORTNAME=	repos-style
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	avk@vl.ru
COMMENT=	Stylesheet for the Subversion index web page

RUN_DEPENDS=	subversion>=0:${PORTSDIR}/devel/subversion

USE_ZIP=	YES
NO_BUILD=	YES

USE_PHP=	xml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/repos-web

SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES+=	pkg-message

pre-install:
# Prevent installation of .orig files by deleting them.
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	${MV} ${WRKSRC}/open/log/index.php ${WRKSRC}/open/log/index.dist.php

do-install:
	@${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${PAX} -r -w . ${WWWDIR})
	if [ ! -f ${WWWDIR}/open/log/index.php ]; then \
		${CP} -p ${WWWDIR}/open/log/index.dist.php ${WWWDIR}/open/log/index.php; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
