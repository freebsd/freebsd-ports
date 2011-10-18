# Ports collection makefile for:	coppermine
# Date created:				05 April 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coppermine
PORTVERSION=	1.5.16
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Coppermine/${PORTVERSION:R}.x/
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A web picture gallery script

OPTIONS=	IMAGEMAGICK "Use ImageMagick instead of php5-gd" off

USE_PHP=	mysql pcre
USE_ZIP=	yes

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/cpg${PORTVERSION:R:R}${PORTVERSION:R:E}x
DOCFILES=	CHANGELOG.txt COPYING.txt README.txt

SUB_FILES+=	pkg-message

.include <bsd.port.options.mk>

.if defined (WITH_IMAGEMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
USE_PHP+=	gd
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default, coppermine depends on PHP with GD support."
	@${ECHO_MSG} "You may define WITH_IMAGEMAGICK to depend on ImageMagick instead of GD."
	@${ECHO_MSG} ""

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}/

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	cd ${WRKSRC}/ && ${RM} ${DOCFILES}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
