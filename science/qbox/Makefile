# $FreeBSD$

PORTNAME=	qbox
DISTVERSIONPREFIX=	rel
DISTVERSION=	1_71_0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	First-principles molecular dynamics code

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libgcc_s.so:lang/gcc${GCC_DEFAULT} \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich \
		libscalapack.so:math/scalapack \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxerces-c.so:textproc/xerces-c3

USES=		compiler:c++11-lang gmake iconv:wchar_t localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	qboxcode
GH_PROJECT=	qbox-public
ALL_TARGET=	qb

WRKSRC_SUBDIR=	src

MAKE_ARGS=	TARGET=freebsd
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} ${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

PLIST_FILES=	bin/qb

post-extract:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|; s|%%CXXFLAGS%%|${CXXFLAGS}|; s|%%LDFLAGS%%|${LDFLAGS}|' < ${FILESDIR}/freebsd.mk.in > ${WRKSRC}/freebsd.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
