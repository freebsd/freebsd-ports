# New ports collection makefile for:	sk-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sk-
DISTNAME=	hyph_sk_SK-${PORTVERSION:C/\.//g}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_sk_SK.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_sk_SK.dic ${DATADIR}/

.include <bsd.port.mk>
