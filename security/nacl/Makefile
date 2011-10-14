# New ports collection makefile for:	nacl
# Date created:		2011-10-03
# Whom:			David Thiel <lx@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nacl
PORTVERSION=	20110221
CATEGORIES=	security
MASTER_SITES=	http://hyperelliptic.org/nacl/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	High speed cryptography library

BROKEN=		does not install

ALL_TARGET=	do
USE_BZIP2=	YES
MAKE_JOBS_UNSAFE=	YES

.include <bsd.port.pre.mk>

HOSTNAME_CMD?=	/bin/hostname

do-build:
	cd ${WRKSRC} && ./do

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha256 \
		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/bin/nacl-sha512 \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/lib/${ARCH}/* \
		${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/build/`${HOSTNAME_CMD} -s`/include/${ARCH}/* \
		${PREFIX}/include

.include <bsd.port.post.mk>
