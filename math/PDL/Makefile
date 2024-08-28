PORTNAME=	PDL
PORTVERSION=	2.089
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Data Language
WWW=		https://metacpan.org/dist/PDL \
		https://pdl.perl.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment; recompile object files with -fPIC or pass '-Wl,-z,notext' to allow text relocations in the output
.endif
BROKEN_aarch64=	ld: error: relocation R_AARCH64_ADR_PREL_PG_HI21 cannot be used against symbol __stack_chk_guard; recompile with -fPIC

BUILD_DEPENDS=	p5-Devel-CheckLib>=1.01:devel/p5-Devel-CheckLib \
		p5-ExtUtils-Depends>=0.402:devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Astro-FITS-Header>=0:astro/p5-Astro-FITS-Header \
		p5-File-Map>=0.57:devel/p5-File-Map \
		p5-Inline>=0.83:devel/p5-Inline \
		p5-Inline-C>=0.62:devel/p5-Inline-C \
		p5-PGPLOT>=2.29:graphics/p5-PGPLOT \
		p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		p5-Sys-SigAction>=0:devel/p5-Sys-SigAction \
		p5-Term-ReadKey>=2.34:devel/p5-Term-ReadKey
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		gmake perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	F77 FFTW GD GSL HDF OPENGL PLPLOT PROJ READLINE SINK
OPTIONS_DEFAULT=F77 FFTW
# graphics/p5-OpenGL require manual building
.if empty(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	OPENGL
.endif
F77_DESC=	Enable PDL::Minuit and PDL::Slatec
FFTW_DESC=	Enable PDL::FFTW
GD_DESC=	Enable PDL::IO::GD
GSL_DESC=	Enable PDL::GSL interface
HDF_DESC=	Enable PDL::IO::HDF interface
OPENGL_DESC=	Enable PDL::Graphics::TriD and OpenGL
PLPLOT_DESC=	Enable PDL::Graphics::PLplot
PROJ_DESC=	Enable PDL::GIS::Proj interface
READLINE_DESC=	Use GNU readline
SINK_DESC=	Include PDL kitchen sink

F77_BUILD_DEPENDS=	p5-ExtUtils-F77>=1.26:lang/p5-ExtUtils-F77
F77_RUN_DEPENDS=	p5-ExtUtils-F77>=1.26:lang/p5-ExtUtils-F77
FFTW_LIB_DEPENDS=	libfftw.so:math/fftw
GD_LIB_DEPENDS=		libgd.so:graphics/gd
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
HDF_LIB_DEPENDS=	libdf.so:science/hdf
OPENGL_BUILD_DEPENDS=	p5-OpenGL>=0.70:graphics/p5-OpenGL
OPENGL_RUN_DEPENDS=	p5-OpenGL>=0.70:graphics/p5-OpenGL
OPENGL_USE=		gl=glu
OPENGL_USES=		gl
PLPLOT_LIB_DEPENDS=	libplplotd.so:math/plplot
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj
READLINE_RUN_DEPENDS=	p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu
READLINE_RUN_DEPENDS_OFF=	p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl
SINK_RUN_DEPENDS=	mpeg_encode:multimedia/mpeg_encode \
			ppmtogif:graphics/netpbm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 503800
BUILD_DEPENDS+=	p5-Text-Balanced>=2.05:textproc/p5-Text-Balanced
RUN_DEPENDS+=	p5-Text-Balanced>=2.05:textproc/p5-Text-Balanced
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Bad/Bad.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/CallExt/CallExt.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Complex/Complex.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Compression/Compression.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Core/Core.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/FFT/FFT.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Fit/Gaussian/Gaussian.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Graphics/IIS/IIS.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Browser/Browser.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Misc/Misc.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Pnm/Pnm.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Storable/Storable.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Image2D/Image2D.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/ImageND/ImageND.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/ImageRGB/ImageRGB.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Math/Math.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/MatrixOps/MatrixOps.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Minuit/Minuit.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Ops/Ops.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Primitive/Primitive.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Slatec/Slatec.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Slices/Slices.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Transform/Transform.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Ufunc/Ufunc.so

.include <bsd.port.post.mk>
