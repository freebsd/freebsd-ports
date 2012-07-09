# New ports collection makefile for:	Math-GSL
# Date created:				15 September 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-GSL
PORTVERSION=	0.27
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl interface to GNU Scientific Library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=1.03:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl
TEST_DEPENDS=	p5-Test-Class>=0.12:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

CFLAGS+=	-I${LOCALBASE}/include
PERL_MODBUILD=	yes

MAN1=		smolder_smoke_signal.1
MAN3=		Math::GSL.3 \
		Math::GSL::BLAS.3 \
		Math::GSL::BSpline.3 \
		Math::GSL::CBLAS.3 \
		Math::GSL::CDF.3 \
		Math::GSL::Chebyshev.3 \
		Math::GSL::Combination.3 \
		Math::GSL::Complex.3 \
		Math::GSL::Const.3 \
		Math::GSL::DHT.3 \
		Math::GSL::Deriv.3 \
		Math::GSL::Diff.3 \
		Math::GSL::Eigen.3 \
		Math::GSL::Errno.3 \
		Math::GSL::FFT.3 \
		Math::GSL::Fit.3 \
		Math::GSL::Heapsort.3 \
		Math::GSL::Histogram.3 \
		Math::GSL::Histogram2D.3 \
		Math::GSL::Integration.3 \
		Math::GSL::Interp.3 \
		Math::GSL::Linalg.3 \
		Math::GSL::Machine.3 \
		Math::GSL::Matrix.3 \
		Math::GSL::MatrixComplex.3 \
		Math::GSL::Min.3 \
		Math::GSL::Monte.3 \
		Math::GSL::Multifit.3 \
		Math::GSL::Multimin.3 \
		Math::GSL::Multiroots.3 \
		Math::GSL::NTuple.3 \
		Math::GSL::ODEIV.3 \
		Math::GSL::Permutation.3 \
		Math::GSL::Poly.3 \
		Math::GSL::PowInt.3 \
		Math::GSL::QRNG.3 \
		Math::GSL::RNG.3 \
		Math::GSL::Randist.3 \
		Math::GSL::Roots.3 \
		Math::GSL::SF.3 \
		Math::GSL::Siman.3 \
		Math::GSL::Sort.3 \
		Math::GSL::Spline.3 \
		Math::GSL::Statistics.3 \
		Math::GSL::Sum.3 \
		Math::GSL::Sys.3 \
		Math::GSL::Test.3 \
		Math::GSL::Vector.3 \
		Math::GSL::VectorComplex.3 \
		Math::GSL::Wavelet.3 \
		Math::GSL::Wavelet2D.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
