# New ports collection makefile for:   fluxcms
# Date created:        31 December 2005
# Whom:                beat
#
# $FreeBSD$
#

PORTNAME=	fluxcms
PORTVERSION=	1.3.1
CATEGORIES=	www
MASTER_SITES=	http://bitflux.org/download/ \
		http://www.chruetertee.ch/files/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beat@chruetertee.ch
COMMENT=	An extensible and flexible CMS based on PHP 5 and XML/XSLT

NO_BUILD=	yes
FLUXCMSDIR=	www/fluxcms
INSTALLDIR=	${PREFIX}/${FLUXCMSDIR}

PLIST_SUB=	INSTALLDIR=${FLUXCMSDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS=	GD "Use GD support instead of ImageMagick" on \
		TIDY "Configure with tidy support" off

USE_PHP=	dom xml simplexml iconv mysql xsl session pcre

BROKEN_WITH_PHP=	4
DEFAULT_PHP_VER=	5

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/${imagick_DEPENDS}
.endif

.if defined(WITH_TIDY)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/tidy.so:${PORTSDIR}/${tidy_DEPENDS}
.endif

do-install:
	@${MKDIR} ${INSTALLDIR}
	@${CP} -R ${WRKSRC}/* ${INSTALLDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${INSTALLDIR}

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
