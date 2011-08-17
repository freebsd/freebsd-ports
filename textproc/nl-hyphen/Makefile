# New ports collection makefile for:	nl-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2005.10.16
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	nl-
DISTNAME=	hyph_nl_NL-${PORTVERSION:C/\.//g}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_nl_NL.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_nl_NL.dic ${DATADIR}/

.include <bsd.port.mk>
