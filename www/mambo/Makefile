# New ports collection makefile for:	www/mambo
# Date created:				Mon Apr 18, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	mambo
PORTVERSION=	4.5.2.2
CATEGORIES=	www
MASTER_SITES=	http://mamboforge.net/frs/download.php/4004/:source1 \
		http://mamboforge.net/frs/download.php/4043/:source2 \
		http://mamboforge.net/frs/download.php/5886/:source3
DISTFILES=	${MAMBO_SRC}:source1 \
		${MAMBO_PATCH1}:source2 \
		${MAMBO_PATCH2}:source3

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	A dynamic web content management system (CMS)

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	mysql session zlib gd pdf xml
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	MAMBO_DIR=${MAMBO_DIR}
PLIST_SUB+=	MAMBO_DIR=${MAMBO_DIR}

MAMBO_DIR?=	www/${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAMBO_SRC=	MamboV4.5.2-Stable.tar.gz
MAMBO_PATCH1=	Patch_4.5.2_to_4.5.2.1.zip
MAMBO_PATCH2=	Patch_4.5.2_to_4.5.2.2.zip

do-extract:
		@${MKDIR} ${WRKSRC}
		@${TAR} -zxf ${DISTDIR}/${DIST_SUBDIR}/${MAMBO_SRC} -C ${WRKSRC}
		@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${MAMBO_PATCH1} -d ${WRKSRC}
		@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${MAMBO_PATCH2} -d ${WRKSRC}
		@${RM} -rf ${WRKSRC}/templates/rhuk_solarflare # remove empty

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
