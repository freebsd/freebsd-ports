# New ports collection makefile for:   nbd-server
# Date created:        14 december 2003
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	nbd-server
PORTVERSION=	2.7.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nbd
DISTNAME=	nbd-${PORTVERSION}

MAINTAINER=	xi@borderworlds.dk
COMMENT=	A server for the linux network block device (nbd)

USE_BZIP2=	yes

HAS_CONFIGURE=	yes
PLIST_FILES=	bin/nbd-server
CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-lfs --enable-syslog

MAN1=		nbd-server.1

post-extract:
	${CP} ${FILESDIR}/nbd.h ${WRKSRC}

.include <bsd.port.mk>
