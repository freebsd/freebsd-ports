# New ports collection makefile for:	clucene
# Date created:		2006-08-09
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clucene
PORTVERSION=	0.9.15
CATEGORIES=	textproc
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	CLucene is a C++ port of Lucene

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ascii
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GCC=	3.2+
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500016
CONFIGURE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
.endif

.include <bsd.port.post.mk>
