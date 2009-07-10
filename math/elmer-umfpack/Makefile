# New ports collection makefile for:	elmer-umfpack
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	umfpack
PORTVERSION=	4.4
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	math
MASTER_SITES=	SF/elmerfem
PKGNAMEPREFIX=	elmer-

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	UMFPACK library used by ELMER FEM package

USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=

# This should be looked up by autoconf
CFLAGS+=	-DGETRUSAGE

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/amd/include/amd.h ${PREFIX}/include/amd_elmer.h
	${INSTALL_DATA} ${WRKSRC}/src/umfpack/include/umfpack.h ${PREFIX}/include/umfpack_elmer.h
	${INSTALL_DATA} ${WRKSRC}/src/amd/libamd.a ${PREFIX}/lib/libamd_elmer.a
	${INSTALL_DATA} ${WRKSRC}/src/amd/libamdf77.a ${PREFIX}/lib/libamdf77_elmer.a
	${INSTALL_DATA} ${WRKSRC}/src/umfpack/libumfpack.a ${PREFIX}/lib/libumfpack_elmer.a

.include <bsd.port.post.mk>
