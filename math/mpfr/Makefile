# New ports collection makefile for:	mpfr
# Date created:			28 Aug 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpfr
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/
DIST_SUBDIR=	mpfr

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library for multiple-precision floating-point computations

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE}
USE_LDCONFIG=	yes

INFO=		mpfr

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
