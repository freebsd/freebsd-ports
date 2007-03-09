# New ports collection makefile for:	b2evolution
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	1.9.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evocms
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A multilingual, multiuser, multi-blog engine

PATCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ZIP=	YES
USE_DOS2UNIX=	YES

B2EVO_DATE?=	2007-01-22
USE_PHP=	mysql pcre session xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${TMPDIR}

B2EVO_URL?=	b2evo
B2EVO_DIR?=	www/${B2EVO_URL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVO_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVO_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVO_DIR} >> ${PLIST}

do-install:
	${MKDIR} ${TARGETDIR}/${B2EVO_DIR}
	@${CHMOD} 755 ${TARGETDIR}/${B2EVO_DIR}
	@${CP} -R ${WRKSRC}/ ${TARGETDIR}/${B2EVO_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TARGETDIR}/${B2EVO_DIR}
	@${CHMOD} 665 ${TARGETDIR}/${B2EVO_DIR}/blogs/conf/_config.php

post-install:
	@${SED} -e 's|%%TARGETDIR%%|${TARGETDIR}|; s|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%B2EVO_DIR%%|${B2EVO_DIR}|; s|%%B2EVO_URL%%|${B2EVO_URL}|' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
