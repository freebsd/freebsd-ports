# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	driftnet
PORTVERSION=	0.1.6
PORTREVISION=	11
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ex-parrot.com/~chris/driftnet/ \
		http://www.vanheusden.com/mirrors/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to grab images out of (your) TCP connections

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib
BUILD_DEPENDS=	makedepend:devel/makedepend

USE_GNOME=	gtk12
USES=		gmake jpeg

ALL_TARGET=	default
PLIST_FILES=	bin/driftnet man/man1/driftnet.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/driftnet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/driftnet.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
