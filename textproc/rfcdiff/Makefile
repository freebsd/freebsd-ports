# New ports collection makefile for: rfcdiff
# Date Created:		11 November 2004
# Whom:			lars.eggert@gmx.net
#
# $FreeBSD$

PORTNAME=	rfcdiff
PORTVERSION=	1.20
CATEGORIES=	textproc
MASTER_SITES=	http://ietf.levkowetz.com/tools/${PORTNAME}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Compare two versions of an Internet Draft and produce a diff

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

PLIST_FILES=	bin/rfcdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
