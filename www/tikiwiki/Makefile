# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	tikiwiki
PORTVERSION=	11.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Tiki_11.x_Vega/${PORTVERSION}/
DISTNAME=	tiki-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

LICENSE=	LGPL20

USE_PHP=	gettext pcre posix session xml zlib
WANT_PHP_WEB=	yes

NO_BUILD=	yes
TIKIWIKI_DIR?=	www/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	TIKIWIKI_DIR=${TIKIWIKI_DIR}
TEMP_PLIST=	${WRKDIR}/temp-pkg-plist
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} TIKIWIKI_DIR=${TIKIWIKI_DIR}
WRKSRC=		${WRKDIR}/${DISTNAME}

# This target is only meant to be used by the port maintainer.
# Stolen from dokuwiki sorry :)

x-generate-plist: extract
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|%%TIKIWIKI_DIR%%/|' > ${TEMP_PLIST} \
		&& ${FIND} -s -d * -type d | \
		${SED} -e 's|^|@dirrm %%TIKIWIKI_DIR%%/|' >> ${TEMP_PLIST} \
		&& ${ECHO_CMD} "@dirrmtry %%TIKIWIKI_DIR%%" >> ${TEMP_PLIST}

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKDIR}
	${TAR} -yxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR}
	@${FIND} ${WRKSRC} -name '.DS_Store' -delete

do-install:
	-${MKDIR} ${PREFIX}/${TIKIWIKI_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${TIKIWIKI_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TIKIWIKI_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
