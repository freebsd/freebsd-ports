# New ports collection makefile for:	driftnet
# Date created:		28 February 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	driftnet
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/ \
		http://www.vanheusden.com/mirrors/

MAINTAINER=	corecode@corecode.ath.cx
COMMENT=	A Tool to grab images out of (your) TCP connections

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_GMAKE=	yes

ALL_TARGET=	default
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN1=	driftnet.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
