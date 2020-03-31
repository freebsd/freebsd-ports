# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Pari
PORTVERSION=	2.01080900
CATEGORIES=	math perl5
MASTER_SITES=	CPAN  \
		http://pari.math.u-bordeaux.fr/pub/pari/unix/OLD/2.3/:pari \
		http://mirrors.rit.edu/zi/:pari
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}.zip \
		pari-2.3.5.tar.gz:pari

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PARI - numerical/scientific/number-theoretic calculations

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_aarch64=		fails to link: mp.c:(function pari_kernel_init): can't create dynamic relocation R_AARCH64_ADR_PREL_PG_HI21 against symbol 'gpmalloc' defined in init.o
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment; recompile object files with -fPIC or pass '-Wl,-z,notext' to allow text relocations in the output
.endif

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		perl5
USE_PERL5=	configure
LLD_UNSAFE=	yes	# lld defaults to -ztext

PARI_WRKSRC=	${WRKDIR}/pari-2.3.5

CFLAGS+=	-I${PARI_WRKSRC}/src/headers -I${PARI_WRKSRC}/build
CFLAGS_powerpc=	-fPIC
CFLAGS_powerpc64=	-fPIC

CONFIGURE_ARGS=	parilib="-L${PARI_WRKSRC}/build -lpari" \
		paridir=${PARI_WRKSRC}
MAKE_ARGS=	LDLOADLIBS="-lm -L${PARI_WRKSRC}/build -Wl,-rpath=${SITE_ARCH}/auto/Math/Pari -lpari"

post-patch:
	@${REINPLACE_CMD} -e 's|2001007|2003000|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -E '/^list=/s/(ld|ranlib|perl|emacs)//g' \
		${PARI_WRKSRC}/Configure
	@${REINPLACE_CMD} -e '/^CFLAGS=/s/\$$cflags//' \
		${PARI_WRKSRC}/config/get_cc

pre-configure:
	cd ${PARI_WRKSRC} && ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
	    INSTALL="/usr/bin/install -c" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ld="${LD}" perl="${PERL}" ranlib="${RANLIB}" \
	    ./Configure --mandir=${MANPREFIX}/man/man1 \
		--prefix=${PREFIX} \
		--share-prefix=${PREFIX}/share \
		--with-gmp=${LOCALBASE}

pre-build:
	cd ${PARI_WRKSRC} && ${DO_MAKE_BUILD:N-j*} gp
	cd ${PARI_WRKSRC} && ln -s $$(dirname $$(readlink gp)) build

post-install:
	${INSTALL_LIB} ${PARI_WRKSRC}/build/libpari-gmp.so.2.3.5 ${STAGEDIR}${SITE_ARCH}/auto/Math/Pari
	${LN} -s libpari-gmp.so.2.3.5 ${STAGEDIR}${SITE_ARCH}/auto/Math/Pari/libpari-gmp.so.2

.include <bsd.port.mk>
