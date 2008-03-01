# New ports collection makefile for:	www/ilias
# Date created:				Oct 24, 2006
# Whom:					Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$

PORTNAME=	ilias
PORTVERSION=	3.7.9
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	r@robakdesign.com
COMMENT=	A poweful, dynamic, PHP and MySQL based e-learning platform

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		zip:${PORTSDIR}/archivers/zip \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear \
		${LOCALBASE}/share/pear/Auth/Auth.php:${PORTSDIR}/security/pear-Auth \
		${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB \
		${LOCALBASE}/share/pear/HTML/Template/IT.php:${PORTSDIR}/devel/pear-HTML_Template_IT
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

NO_BUILD=		yes
SUB_FILES=		pkg-message
USE_MYSQL=		yes
DEFAULT_MYSQL_VER=	50
USE_PHP=		mysql session zlib gd pdf xml pcre
DEFAULT_PHP_VER=	5
WANT_PHP_MOD=		yes
WRKSRC=			${WRKDIR}/ilias3
PLIST=			${WRKDIR}/pkg-plist

INSTALL_DIR?=	www/${PORTNAME}

OPTIONS=	PHP4 "Use PHP4 instead of PHP5" off \
		MYSQL4 "Use MySQL 4.x instead of MySQL 5.x" off

.include <bsd.port.pre.mk>

.if defined(WITH_PHP4)
DEFAULT_PHP_VER=	4
LIB_DEPENDS+=		sablot.70:${PORTSDIR}/textproc/sablotron
.endif

.if defined(WITH_MYSQL4)
DEFAULT_MYSQL_VER=	41
.endif

PLIST_SUB=	INSTALL_DIR=${INSTALL_DIR}

pre-install:
		@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${INSTALL_DIR}?g" >${PLIST}
		@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${INSTALL_DIR}?g" >> ${PLIST}

do-install:
		@${MKDIR} ${PREFIX}/${INSTALL_DIR}
		@cd ${WRKSRC} && ${FIND} . | ${PAX} -rw ${PREFIX}/${INSTALL_DIR}
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${INSTALL_DIR}

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
