# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0-beta.2-20
DISTVERSIONSUFFIX=	-gc2e0a72
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_10=	/usr/include/c++/v1/memory:4004:35: error: no viable overloaded '=': __e->__weak_this_ = *this;

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmpxx.so:math/gmp

USES=		autoreconf:build compiler:c++11-lang gmake libtool localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	evaleev
GH_PROJECT=	${PORTNAME:S/2//}
USE_LDCONFIG=	yes
ALL_TARGET=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --with-cc-optflags="${CFLAGS}" \
		--with-cxx-optflags="${CXXFLAGS}"

DATADIR=	${PREFIX}/share/${PORTNAME:S/2//}

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
