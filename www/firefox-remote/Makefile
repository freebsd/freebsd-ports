# New ports collection makefile for:	firefox-remote
# Date created:				13 May 2004
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	20040513
CATEGORIES=	www
MASTER_SITES=	http://www.webonaut.com/distfiles/${PORTNAME}${PKGNAMESUFFIX}/
PKGNAMESUFFIX=	-remote
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
EXTRACT_SUFX=	.bz2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Wrapper script for firefox web browser

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	> ${PORTNAME}

do-build:
	@${REINPLACE_CMD} -e 's|@X11BASE@|${PREFIX}|g' \
		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
