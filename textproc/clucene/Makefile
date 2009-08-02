# New ports collection makefile for:	clucene
# Date created:		2006-08-09
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clucene
PORTVERSION=	0.9.21
CATEGORIES=	textproc
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	CLucene is a C++ port of Lucene

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

.include <bsd.port.pre.mk>

.if defined(WITH_ASCII_SUPPORT)
CONFIGURE_ARGS+=	--enable-ascii
.endif

.include <bsd.port.post.mk>
