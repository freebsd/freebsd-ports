# New ports collection makefile for:	sk-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2011.08.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.sk-spell.sk.cx/thesaurus/download/
PKGNAMEPREFIX=	sk-
DISTNAME=	OOo-Thesaurus2-sk_SK

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_sk_SK_v2.dat \
		%%DATADIR%%/th_sk_SK_v2.idx
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_sk_SK_v2.dat ${WRKSRC}/th_sk_SK_v2.idx ${DATADIR}/

.include <bsd.port.mk>
