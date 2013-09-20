# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gmp-ecm
PORTVERSION=	6.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/26838/
DISTNAME=	ecm-${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Elliptic Curve Method for Integer Factorization

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS=	ecm-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_XSLTPROC=no \
		--with-gmp=${LOCALBASE}

MAN1=		ecm.1
PLIST_FILES=	bin/ecm include/ecm.h lib/libecm.a lib/libecm.la

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} s/__GMP_BITS_PER_MP_LIMB/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h
	@${REINPLACE_CMD} s/GMP_BITS_PER_LIMB/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h
	@${REINPLACE_CMD} s/mp_bits_per_limb/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>
