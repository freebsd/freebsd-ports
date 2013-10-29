# Created by: Chin-San Huang <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	dokuwiki
PORTVERSION=	${DIST_VER:S/${PORTNAME}//:S/-//g}
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/_media/projects/dokuwiki/ \
		LOCAL/chinsan/${PORTNAME}
DISTNAME=	${DIST_VER}
EXTRACT_SUFX=	.tgz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	A simple and easy to use wiki, no database required

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DIST_VER=	${PORTNAME}-2013-05-10
USE_PHP=	gd mbstring openssl pcre session xml zlib
NO_BUILD=	YES
WANT_PHP_WEB=	YES

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}
SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/bin/*.php
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${RM} ${WRKSRC}/data/deleted.files

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
