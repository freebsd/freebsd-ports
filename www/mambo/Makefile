# New ports collection makefile for:	www/mambo
# Date created:				Mon Apr 18, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	mambo
PORTVERSION=	4.6.1
CATEGORIES=	www
MASTER_SITES=	http://mamboxchange.com/frs/download.php/8290/:source1
DISTFILES=	${MAMBO_SRC}:source1

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	A dynamic web content management system (CMS)

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql session zlib gd pdf xml pcre
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	MAMBO_DIR=${MAMBO_DIR}
PLIST_SUB+=	MAMBO_DIR=${MAMBO_DIR}

MAMBO_DIR?=	www/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAMBO_SRC=	MamboV4.6.1.zip

do-extract:
		@${MKDIR} ${WRKSRC}
		@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${MAMBO_SRC} -d ${WRKSRC}
#		@${RM} -rf ${WRKSRC}/templates/rhuk_solarflare # remove empty

do-install:
		@${MKDIR} ${PREFIX}/${MAMBO_DIR}
		@cd ${WRKSRC} && \
			${FIND} . -type d -exec ${MKDIR} ${PREFIX}/${MAMBO_DIR}/{} \; \
				-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAMBO_DIR}/{} \;
		@cd ${WRKSRC} && \
			${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${PREFIX}/${MAMBO_DIR}/{} \; \
				-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAMBO_DIR}/{} \;

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
