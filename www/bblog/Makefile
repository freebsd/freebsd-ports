# New ports collection makefile for:	bBlog
# Date created:		2005-04-16
# Whom:			chinsan@mail2000.com.tw
#
# $FreeBSD$
#

PORTNAME=	bBlog
PORTVERSION=	0.7.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bblog
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A elegant personal publishing system with Smarty

USE_PHP=	mysql pcre session
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	blog
WRKSRC=		${WRKDIR}/${TMPDIR}
WWWDOCROOT?=	www/data-dist
BBLOGURL?=	bblog
WWWOWN?=	www
WWWGRP?=	www
BBLOGDIR?=	${WWWDOCROOT}/${BBLOGURL}
PLIST=		${WRKDIR}/pkg-plist

OPTIONS=	GD		"With GD Support" on \
		IMAGICK		"With ImageMagick Support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.endif

.if defined(WITH_IMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/${imagick_DEPENDS}
.endif

.if defined(WITHOUT_GD) && !defined(WITH_IMAGICK)
pre-patch:
	@${ECHO_CMD} "Without GD or ImageMagick support. No thumbnails will be generated at all."
.endif

pre-install:
	cd ${WRKSRC}/${BBLOGURL} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${BBLOGDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${BBLOGDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${BBLOGDIR} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${BBLOGDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${BBLOGDIR}
	@${CHMOD} 755 ${PREFIX}/${BBLOGDIR}
	@${CP} -R ${WRKSRC}/${BBLOGURL}/ ${PREFIX}/${BBLOGDIR}
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/install.php
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/compiled_templates/
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/cache/
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/cache/favorites.xml
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/config.php

post-install:
	@${SED} -e 's|%%BBLOGURL%%|${BBLOGURL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
