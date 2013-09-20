# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	driftnet
PORTVERSION=	0.1.6
PORTREVISION=	7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/ \
		http://www.vanheusden.com/mirrors/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tool to grab images out of (your) TCP connections

LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		jpeg.11:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_GNOME=	gtk12
USE_GMAKE=	yes

ALL_TARGET=	default
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN1=		driftnet.1
PLIST_FILES=	bin/driftnet

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
