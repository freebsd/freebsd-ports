# New ports collection makefile for:   nbd-server
# Date created:        14 december 2003
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	nbd-server
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nbd
DISTNAME=       nbd-${PORTVERSION}

MAINTAINER=	xi@borderworlds.dk
COMMENT=	A server for the linux network block device (nbd)

WRKSRC=		${WRKDIR}/nbd-2.6

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	yes

post-extract:
	${CP} ${FILESDIR}/nbd.h ${WRKSRC}

.include <bsd.port.mk>
