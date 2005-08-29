# New ports collection makefile for:	mpfr
# Date created:			28 Aug 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpfr
PORTVERSION=	2.1.2
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library for multiple-precision floating-point computations

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}

INFO=		mpfr

.include <bsd.port.mk>
