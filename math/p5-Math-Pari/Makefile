PORTNAME=	Math-Pari
PORTVERSION=	2.030518
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN  \
		http://pari.math.u-bordeaux.fr/pub/pari/unix/OLD/2.3/:pari \
		http://mirrors.rit.edu/zi/:pari
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}.zip \
		pari-2.3.5.tar.gz:pari

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Numerical/scientific/number-theoretic calculations
WWW=		https://metacpan.org/dist/Math-Pari

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		perl5
USE_PERL5=	configure

PARI_WRKSRC=	${WRKDIR}/pari-2.3.5

CFLAGS+=	-I${PARI_WRKSRC}/src/headers -I${PARI_WRKSRC}/build
CFLAGS_aarch64=		-fPIC
CFLAGS_powerpc=		-fPIC
CFLAGS_powerpc64=	-fPIC
CFLAGS_powerpc64le=	-fPIC
CFLAGS_powerpcspe=	-fPIC
CFLAGS_riscv64=		-fPIC

CONFIGURE_ARGS=	parilib="-L${PARI_WRKSRC}/build -lpari" \
		paridir=${PARI_WRKSRC}
MAKE_ARGS=	LDLOADLIBS="-lm -L${PARI_WRKSRC}/build -Wl,-rpath=${SITE_ARCH}/auto/Math/Pari -lpari"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|2001007|2003000|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -E '/^list=/s/(ld|ranlib|perl|emacs)//g' \
		${PARI_WRKSRC}/Configure
	@${REINPLACE_CMD} -e '/^CFLAGS=/s/\$$cflags//' \
		${PARI_WRKSRC}/config/get_cc
.if ${ARCH} == "i386"
	${REINPLACE_CMD} -e 's|-Wl|-Wl,-znotext|' ${PARI_WRKSRC}/config/ldflags
.endif
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
	    ./Configure --mandir=${PREFIX}/share/man/man1 \
		--prefix=${PREFIX} \
		--share-prefix=${PREFIX}/share \
		--with-gmp=${LOCALBASE}

pre-build:
	cd ${PARI_WRKSRC} && ${DO_MAKE_BUILD:N-j*} gp
	cd ${PARI_WRKSRC} && ln -s $$(dirname $$(readlink gp)) build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Pari/Pari.so
	${INSTALL_LIB} ${PARI_WRKSRC}/build/libpari-gmp.so.2.3.5 ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Pari
	${LN} -s libpari-gmp.so.2.3.5 ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/Pari/libpari-gmp.so.2

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 504200
BROKEN=	fails to build
.endif

.include <bsd.port.post.mk>
