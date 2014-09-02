# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	tikiwiki
PORTVERSION=	13.0
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Tiki_13.x_Fomalhaut/${PORTVERSION}/
DISTNAME=	tiki-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

LICENSE=	LGPL20

USE_PHP=	gettext pcre posix session xml zlib
WANT_PHP_WEB=	yes

NO_BUILD=	yes
NO_MTREE=	yes
TIKIWIKI_DIR?=	www/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} TIKIWIKI_DIR=${TIKIWIKI_DIR}

post-extract:
	@${FIND} ${WRKSRC} -name '.DS_Store' -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TIKIWIKI_DIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${TIKIWIKI_DIR})

# pkg-plist would be over 15,000 lines, consuming 1.1Mb
# The benefits of a fixed pkg-plist aren't worth it, autogen!

post-install:
	@echo "@owner ${WWWOWN}" >> ${TMPPLIST}
	@echo "@group ${WWWGRP}" >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
		${SORT} >> ${TMPPLIST})
	@echo "@owner" >> ${TMPPLIST}
	@echo "@group" >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | \
		${SORT} -r | ${SED} -e 's/^/@dirrm /g' >> ${TMPPLIST})

.include <bsd.port.mk>
