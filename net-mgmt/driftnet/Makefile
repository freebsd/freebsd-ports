# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	driftnet
PORTVERSION=	0.1.6
PORTREVISION=	8
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/ \
		http://www.vanheusden.com/mirrors/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to grab images out of (your) TCP connections

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
	 	libjpeg.so:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_GNOME=	gtk12
USES=		gmake

ALL_TARGET=	default
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

PLIST_FILES=	bin/driftnet man/man1/driftnet.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
