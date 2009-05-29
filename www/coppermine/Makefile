# Ports collection makefile for:	coppermine
# Date created:				05 April 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coppermine
PORTVERSION=	1.4.23
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A web picture gallery script

USE_PHP=	mysql pcre
USE_ZIP=	yes

.if defined (WITH_IMAGEMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
USE_PHP+=	gd
.endif

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/cpg14x
DOCFILES=	CHANGELOG COPYING README.txt

SUB_FILES+=	pkg-message

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default, coppermine depends on PHP with GD support."
	@${ECHO_MSG} "You may define WITH_IMAGEMAGICK to depend on ImageMagick instead of GD."
	@${ECHO_MSG} ""

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	@cd ${WRKSRC} && ${RM} ${DOCFILES}
	-${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR})
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
