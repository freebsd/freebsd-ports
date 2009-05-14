# New ports collection makefile for:	mpc
# Date created:			05 April, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpc
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	wenheping@gmail.com
COMMENT=	Library of complex numbers with arbitrarily high precision

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4 \
		mpfr.3:${PORTSDIR}/math/mpfr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE}
USE_LDCONFIG=	yes

INFO=		mpc

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
