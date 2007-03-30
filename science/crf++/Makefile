# New ports collection makefile for:	crf++
# Date created:		2006-07-27
# Whom:			Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	crf++
PORTVERSION=	0.47
CATEGORIES=	science math
MASTER_SITES=	http://chasen.org/~taku/software/CRF++/src/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	clsung/${PORTNAME}
DISTNAME=	CRF++-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Yet Another CRF toolkit

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GCC=	3.2+

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500016
MAKE_ARGS+=	LDFLAGS=${PTHREAD_LIBS}
.endif

.include <bsd.port.post.mk>
