# New ports collection makefile for:	Elmer-MatC
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	matc
PORTVERSION=	5.4.0
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://garr.dl.sourceforge.net/sourceforge/elmerfem/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	MatC language library used by ELMER FEM package

CXXFLAGS+=	-Wno-deprecated

GNU_CONFIGURE=	yes
USE_FORTRAN=	g77

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
