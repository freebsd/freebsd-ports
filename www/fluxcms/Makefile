# New ports collection makefile for:   fluxcms
# Date created:        31 December 2005
# Whom:                beat
#
# $FreeBSD$
#

PORTNAME=	fluxcms
PORTVERSION=	1.6.0
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://bitflux.org/download/ \
		http://www.chruetertee.ch/files/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-snapshot-20080801
EXTRACT_SUFX=	.tgz

MAINTAINER=	beat@chruetertee.ch
COMMENT=	An extensible and flexible CMS based on PHP 5 and XML/XSLT

NO_BUILD=	yes
FLUXCMSDIR=	www/fluxcms
INSTALLDIR=	${PREFIX}/${FLUXCMSDIR}

PLIST_SUB=	INSTALLDIR=${FLUXCMSDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	INSTALLDIR=${INSTALLDIR}

OPTIONS=	TIDY "Configure with tidy support" off

USE_PHP=	dom xml simplexml iconv mysql xsl session pcre gd

IGNORE_WITH_PHP=	4
DEFAULT_PHP_VER=	5

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.include <bsd.port.pre.mk>

.if defined(WITH_TIDY)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/tidy.so:${PORTSDIR}/${tidy_DEPENDS}
.endif

post-patch:
	@${RM}  ${WRKSRC}/install/dist/conf/config.xml.orig

do-install:
	@${MKDIR} ${INSTALLDIR}
	@${CP} -R ${WRKSRC}/* ${INSTALLDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${INSTALLDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
