# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	gmp-ecm
DISTVERSION=	7.0.4
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/36224/
DISTNAME=	ecm-${DISTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Elliptic Curve Method for Integer Factorization

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgmp.so:math/gmp

CONFLICTS=	ecm-[0-9]*

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_XSLTPROC=no \
		--with-gmp=${LOCALBASE} \
		--enable-shared \
		--disable-static
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ecm include/ecm.h \
		lib/libecm.so \
		lib/libecm.so.1 \
		lib/libecm.so.1.0.0 \
		man/man1/ecm.1.gz

post-patch:
	@${REINPLACE_CMD} s/__GMP_BITS_PER_MP_LIMB/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h
	@${REINPLACE_CMD} s/GMP_BITS_PER_LIMB/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h
	@${REINPLACE_CMD} s/mp_bits_per_limb/GMP_NUMB_BITS/g \
		${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>
