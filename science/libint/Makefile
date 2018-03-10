# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint
DISTVERSIONPREFIX=	release-
DISTVERSION=	1-1-6
PORTREVISION=	7
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	evaleev

# USE_GCC=yes is required because libint is used with mpqc which is built
# by gfortran (via USES=fortran) and these two libraries each try to pull
# in libgcc_s.so which fails if it's different versions.  Forcing this port
# to build with the default version of GCC as well resolves the conflict
# that manifests in the science/libghemical port.
USES=		autoreconf:build gmake libtool perl5
USE_GCC=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-cc-optflags="${CFLAGS}" \
		--with-cxx-optflags="${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's| -rpath|${LDFLAGS} -rpath|g' \
		${WRKSRC}/src/lib/MakeVars.in

pre-configure:
# Cannot run autoheader so cannot use autoreconf.
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize -c -f \
		&& ${LOCALBASE}/bin/aclocal && ${LOCALBASE}/bin/autoconf)

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
