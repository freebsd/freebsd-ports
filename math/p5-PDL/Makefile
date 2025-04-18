PORTNAME=	PDL
PORTVERSION=	2.100
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Data Language
WWW=		https://metacpan.org/dist/PDL \
		https://pdl.perl.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_aarch64=	ld: error: relocation R_AARCH64_ADR_PREL_PG_HI21 cannot be used against symbol __stack_chk_guard; recompile with -fPIC
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment; recompile object files with -fPIC or pass '-Wl,-z,notext' to allow text relocations in the output
.endif

BUILD_DEPENDS=	p5-Devel-CheckLib>=1.01:devel/p5-Devel-CheckLib \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Astro-FITS-Header>=2.1:astro/p5-Astro-FITS-Header \
		p5-File-Map>=0.57:devel/p5-File-Map \
		p5-Inline>=0.83:devel/p5-Inline \
		p5-Inline-C>=0.62:devel/p5-Inline-C \
		p5-Pod-Parser>=0:textproc/p5-Pod-Parser \
		p5-Sys-SigAction>=0:devel/p5-Sys-SigAction \
		p5-Term-ReadKey>=2.34:devel/p5-Term-ReadKey
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		gmake perl5
USE_PERL5=	configure

MAKE_ENV=	POSIX_THREADS_LIBS='-lpthread'
MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	FFTW READLINE SINK
OPTIONS_DEFAULT=FFTW
FFTW_DESC=	Enable PDL::FFTW
READLINE_DESC=	Use GNU readline
SINK_DESC=	Include PDL kitchen sink

FFTW_LIB_DEPENDS=	libfftw.so:math/fftw
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Compression/Compression.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Core/Core.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/FFT/FFT.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Misc/Misc.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/IO/Pnm/Pnm.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Image2D/Image2D.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/ImageND/ImageND.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/ImageRGB/ImageRGB.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Math/Math.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/MatrixOps/MatrixOps.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Ops/Ops.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Primitive/Primitive.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Slices/Slices.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Transform/Transform.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL/Ufunc/Ufunc.so

.include <bsd.port.post.mk>
