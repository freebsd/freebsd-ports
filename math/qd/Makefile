# New ports collection makefile for:    qd
# Date created:                         2007/03/28
# Whom:                                 Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qd
PORTVERSION=	2.2.4
CATEGORIES=	math
MASTER_SITES=	http://www.cs.berkeley.edu/~yozo/software/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Double-Double and Quad-Double Arithmetic

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
CONFIGURE_ENV+=	FC="${FC}" FFLAGS="${FFLAGS}"
CONFIGURE_ARGS+=	--enable-shared=yes

.include <bsd.port.post.mk>
