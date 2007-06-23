# New ports collection makefile for:	www/joomla
# Date created:				Sat Out 15, 2005
# Whom:					Francisco Cabrita <include@npf.pt.freebsd.org>
#
# $FreeBSD$

PORTNAME=	joomla
PORTVERSION=	1.0.12
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://downloads.joomlacode.org/frsrelease/2/6/4/264/
DISTNAME=	Joomla_${PORTVERSION}-Stable-Full_Package
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	A dynamic web content management system (CMS)

NO_BUILD=	yes
USE_BZIP2=	yes
USE_MYSQL=	yes
USE_PHP=	mysql pcre xml zlib session gd pdf
WANT_PHP_WEB=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && \
		${FIND} . -type d -exec ${MKDIR} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;
	@cd ${WRKSRC} && \
		${FIND} . \! -type d -exec ${INSTALL_DATA} {} ${WWWDIR}/{} \; \
			-exec ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}/{} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
