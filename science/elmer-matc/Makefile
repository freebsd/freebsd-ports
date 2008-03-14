# New ports collection makefile for:	Elmer-MatC
# Date created:		5 Jan 2006
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	matc
PORTVERSION=	5.4.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF/elmerfem
PKGNAMEPREFIX=	elmer-

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	MatC language library used by ELMER FEM package

GNU_CONFIGURE=	yes
ALL_TARGET=

USE_FORTRAN=	yes

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
