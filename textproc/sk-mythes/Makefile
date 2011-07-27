# New ports collection makefile for:	sk-mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sk-mythes
PORTVERSION=	2011.07.26
CATEGORIES=	textproc
MASTER_SITES=	http://www.sk-spell.sk.cx/thesaurus/download/
DISTNAME=	OOo-Thesaurus2-sk_SK

MAINTAINER=	office@FreeBSD.org
COMMENT=	Slovak thesaurus

LICENSE=	BSD

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	share/mythes/th_sk_SK_v2.dat \
		share/mythes/th_sk_SK_v2.idx
PLIST_DIRSTRY=	share/mythes

do-install:
	${MKDIR} ${PREFIX}/share/mythes/
	${INSTALL_DATA} ${WRKSRC}/th_sk_SK_v2.dat ${WRKSRC}/th_sk_SK_v2.idx ${PREFIX}/share/mythes/

.include <bsd.port.mk>
