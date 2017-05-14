# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint
DISTVERSIONPREFIX=	release-
DISTVERSION=	1-1-6
PORTREVISION=	3
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
USES=		autoreconf gmake libtool perl5
USE_GCC=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-cc-optflags="${CFLAGS}" \
		--with-cxx-optflags="${CXXFLAGS}"

OPTIONS_DEFINE=	DEBUG DERIV R12

DERIV_DESC=	1st- and 2nd-order derivative ERI support
R12_DESC=	Linear R12 methods integrals support

DEBUG_CONFIGURE_ON=	--enable-debug
DERIV_CONFIGURE_ON=	--enable-deriv
R12_CONFIGURE_ON=	--enable-r12

post-patch:
	@${REINPLACE_CMD} -e 's| -rpath|${LDFLAGS} -rpath|g' \
		${WRKSRC}/src/lib/MakeVars.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
