# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	matc
PORTVERSION=	5.4.0
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://garr.dl.sourceforge.net/sourceforge/elmerfem/
PKGNAMEPREFIX=	elmer-

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MatC language library used by ELMER FEM package

CXXFLAGS+=	-Wno-deprecated

GNU_CONFIGURE=	yes
USES=		fortran

PLIST_SUB=	ARCH=${MACHINE_ARCH}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
