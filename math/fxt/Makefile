# ex:ts=8
# New ports collection makefile for:	fxt
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fxt
PORTVERSION=	2003.02.18
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKEFILE=	makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif


.include <bsd.port.post.mk>
