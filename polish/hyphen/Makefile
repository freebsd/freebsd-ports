# New ports collection makefile for:	hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2007.04.16
PORTREVISION=	1
CATEGORIES=	polish textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	hyph_pl_PL-${PORTVERSION:C/\.//g}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Polish hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_pl_PL.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_pl_PL.dic ${DATADIR}/

.include <bsd.port.mk>
