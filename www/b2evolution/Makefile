# New ports collection makefile for:	b2evolution
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	2.4.6
CATEGORIES=	www
MASTER_SITES=	SF/evocms/${PORTNAME}/b2evo%20${PORTVERSION}-stable
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	A multilingual, multiuser, multi-blog engine

PATCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ZIP=	YES
USE_DOS2UNIX=	YES

B2EVO_DATE?=	stable-2009-01-12-lc
USE_PHP=	mysql pcre session xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${TMPDIR}
B2EVO_URL?=	b2evo
B2EVO_DIR?=	www/${B2EVO_URL}
PLIST=		${WRKDIR}/pkg-plist
WARNING=	${PKGDIR}/pkg-warning

OPTIONS=	LOCAL_DB_SERVER "Want to use local MySQL server?" on

.include <bsd.port.pre.mk>

.if defined(WITH_LOCAL_DB_SERVER)
USE_MYSQL=	YES
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

pre-everything::
	@${SH} ${WARNING}

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVO_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVO_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVO_DIR} >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${B2EVO_DIR}
	@${CHMOD} 755 ${PREFIX}/${B2EVO_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${B2EVO_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${B2EVO_DIR}
	@${CHMOD} 665 ${PREFIX}/${B2EVO_DIR}/blogs/conf/_config.php

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%B2EVO_DIR%%|${B2EVO_DIR}|; s|%%B2EVO_URL%%|${B2EVO_URL}|' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
