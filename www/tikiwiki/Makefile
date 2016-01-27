# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	tikiwiki
PORTVERSION=	14.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Tiki_14.x_Peony/${PORTVERSION}/
DISTNAME=	tiki-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/license.txt

USE_PHP=	gettext pcre posix session xml zlib
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_MTREE=	yes
TIKIWIKI_DIR?=	www/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST+=	TIKIWIKI_DIR=${TIKIWIKI_DIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIKIWIKI_DIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${TIKIWIKI_DIR})

# pkg-plist would be over 15,000 lines, consuming 1.1Mb
# The benefits of a fixed pkg-plist aren't worth it, autogen!

post-install:
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
		${SORT} | ${SED} -e 's/^/@(${WWWOWN},${WWWGRP},) /' >> ${TMPPLIST})
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d -empty | \
		${SORT} -r | ${SED} -e 's/^/@dir /' >> ${TMPPLIST})

.include <bsd.port.mk>
