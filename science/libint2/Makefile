PORTNAME=	libint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.1
CATEGORIES=	science
PKGNAMESUFFIX=	2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory
WWW=		https://github.com/evaleev/libint

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmpxx.so:math/gmp

USES=		autoreconf:build compiler:c++11-lang gmake libtool localbase:ldflags
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	evaleev
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-1body=1 --enable-eri=1 --enable-eri3=1 --enable-eri2=1 --enable-contracted-ints \
		--with-cc-optflags="${CFLAGS}" --with-cxx-optflags="${CXXFLAGS}"

ALL_TARGET=	default

PLIST_SUB=	VER=${DISTVERSION}

OPTIONS_DEFINE=			STATIC # osa@ requested to keep static libs on 2018/08/28
OPTIONS_SUB=			yes

STATIC_CONFIGURE_ENABLE=	static

post-patch:
	@${REINPLACE_CMD} -e 's| -rpath|${LDFLAGS} -rpath|g' \
		${WRKSRC}/src/lib/MakeVars.in

pre-configure:
# Cannot run autoheader so cannot use autoreconf.
	@cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize -c -f \
		&& ${LOCALBASE}/bin/aclocal && ${LOCALBASE}/bin/autoconf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
