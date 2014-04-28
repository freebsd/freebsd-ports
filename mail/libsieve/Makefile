# Created by: Mark Starovoytov <mark_sf@kikg.ifmo.ru>
# $FreeBSD$

PORTNAME=	libsieve
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing, sorting, and filtering mail

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	sodabrew

USES=		bison gmake pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
