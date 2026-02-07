PORTNAME=	qbox
DISTVERSIONPREFIX=	rel
DISTVERSION=	1_78_4
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	First-principles molecular dynamics code
WWW=		http://qboxcode.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		liblapack.so:math/lapack \
		libmpicxx.so:net/mpich \
		libscalapack.so:math/scalapack \
		libuuid.so:misc/libuuid \
		libxerces-c.so:textproc/xerces-c3

USES=		compiler:c++11-lang gmake iconv:wchar_t localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	qboxcode
GH_PROJECT=	qbox-public

WRKSRC_SUBDIR=	src

MAKE_ARGS=	TARGET=freebsd

ALL_TARGET=	qb
TEST_TARGET=	tests
TESTING_UNSAFE=	only builds tests, but doesn't run them: https://github.com/qboxcode/qbox-public/issues/6, tests fail to link, see https://github.com/qboxcode/qbox-public/issues/11

PLIST_FILES=	bin/qb

post-extract:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|; s|%%CXXFLAGS%%|${CXXFLAGS}|; s|%%LDFLAGS%%|${LDFLAGS}|' < ${FILESDIR}/freebsd.mk.in > ${WRKSRC}/freebsd.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qb ${STAGEDIR}${PREFIX}/bin

# tests fail to compile, see https://github.com/qboxcode/qbox-public/issues/12

.include <bsd.port.mk>
