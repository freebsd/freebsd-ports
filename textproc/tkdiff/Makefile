# New ports collection makefile for:	tkdiff
# Date created:		4 Oct. 1999
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdiff
PORTVERSION=	4.2
CATEGORIES=	textproc tk
MASTER_SITES=	SF

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A Tk frontend for diff(1)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-unix

USE_TK_WRAPPER=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/tkdiff

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${PREFIX}/bin

.include <bsd.port.mk>
