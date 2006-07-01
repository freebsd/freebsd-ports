# New ports collection makefile for:	elmer-meshgen2d
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	meshgen2d
PORTVERSION=	5.0.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.funet.fi/pub/sci/physics/elmer/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Mesh Generation Utility for use with the ELMER FEM package

USE_GCC=	4.1+
GNU_CONFIGURE=	yes
ALL_TARGET=

PLIST_FILES=	bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-ElmerMesh2D \
		bin/${MACHINE_ARCH}-portbld-freebsd${OSREL}-Mesh2D

.include <bsd.port.mk>
