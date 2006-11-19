# New ports collection makefile for:	mpfr
# Date created:			28 Aug 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpfr
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	math devel
MASTER_SITES=	http://www.mpfr.org/mpfr-current/
DIST_SUBDIR=	mpfr

PATCH_SITES=	${MASTER_SITES}
PATCHLEVEL=	16
PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A library for multiple-precision floating-point computations

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--enable-shared
USE_LDCONFIG=	yes

INFO=		mpfr

post-patch:
	@${TOUCH} ${WRKSRC}/*

.include <bsd.port.mk>
