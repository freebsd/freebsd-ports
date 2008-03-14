# New ports collection makefile for:	elmer-meshgen2d
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	meshgen2d
PORTVERSION=	5.0.0
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	SF/elmerfem
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A Mesh Generation Utility for use with the ELMER FEM package

USE_FORTRAN=	yes

GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D \
		bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D	\
		bin/ElmerMesh2D bin/Mesh2D

post-install:
		${LN} -sf ${PREFIX}/bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D \
			${PREFIX}/bin/ElmerMesh2D
		${LN} -sf ${PREFIX}/bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D \
			${PREFIX}/bin/Mesh2D

.include <bsd.port.mk>
