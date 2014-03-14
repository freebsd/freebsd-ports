# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=		yourls
DISTVERSION=		1.5.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=		joehorn@gmail.com
COMMENT=		Your Own URL Shortener

LICENSE=		GPLv3

WRKSRC=			${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		zip:infozip
NO_BUILD=		YES

USE_PHP=		bcmath curl json mysql pcre xml

SUB_LIST+=		PKGNAME=${PKGNAME}
SUB_FILES+=		pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
