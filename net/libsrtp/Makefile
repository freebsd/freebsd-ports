# New ports collection makefile for:   libsrtp
# Date created:        2 May 2011
# Whom:                Alexander Brovikov <alexander@brovikov.ru>
#
# $FreeBSD$
#

PORTNAME=	libsrtp
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${ORIGNAME}/${ORIGNAME}/${PORTVERSION}
DISTNAME=	${ORIGNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alexander@brovikov.ru
COMMENT=	A library implementing Secure RTP

WRKSRC=		${WRKDIR}/${ORIGNAME}
ORIGNAME=	srtp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-fPIC

.include <bsd.port.mk>
