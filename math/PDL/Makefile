# New ports collection makefile for:	PDL
# Date created:		08 February 1999
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	PDL
PORTVERSION=	2.1.1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PDL

MAINTAINER=	tobez@plab.ku.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/ExtUtils/F77.pm:${PORTSDIR}/lang/p5-F77
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ReadLine/readline.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

USE_MESA=	yes
USE_PERL5=	yes
SCRIPTS_ENV=	PERL=${PERL}

.if defined(KITCHEN_SINK)
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw \
		gsl.0:${PORTSDIR}/math/gsl
RUN_DEPENDS+=	ppmtogif:${PORTSDIR}/graphics/netpbm \
		mpeg_encode:${PORTSDIR}/graphics/mpeg_encode \
		saoimage:${PORTSDIR}/astro/saoimage
.endif

.SILENT:

.if !defined(KITCHEN_SINK)
pre-extract:
	${ECHO} "You can build additional functionality into PDL by defining KITCHEN_SINK"
.endif

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
BROKEN=	test script t/flexraw.t fails all 26 tests
.endif

.if ${OSVERSION} >= 500007
PLIST_SUB+=	NEW_PERL:="" OLD_PERL:="@comment "
.else
PLIST_SUB+=	NEW_PERL:="@comment " OLD_PERL:=""
.endif

MAN1=	PDL::Philosophy.1 PDL::Internals.1 PDL::PP.1 PDL::Tips.1 \
	PDL::Dataflow.1 PDL::Indexing.1 PDL::FAQ.1 PDL::Delta.1 \
	PDL::Objects.1 PDL::Impatient.1 pdl.1 perldl.1
MAN3=	PDL.3 PDL::Char.3 PDL::Complex.3 PDL::Fit::Gaussian.3 PDL::Func.3 \
	PDL::Graphics::LUT.3 PDL::LM.3 PDL::Polynomial.3 \
	PDL::PP::Dump.3 PDL::PP::Signature.3 PDL::Types.3 PDL::Dbg.3 \
	PDL::Exporter.3 PDL::Core.3 PDL::Basic.3 PDL::Lite.3 PDL::LiteF.3 \
	PDL::Ops.3 PDL::Options.3 PDL::Primitive.3 \
	PDL::Slices.3 PDL::Tests.3 PDL::Math.3 PDL::AutoLoader.3 \
	PDL::Pod::Usage.3 PDL::Pod::Parser.3 \
	PDL::Pod::Select.3 PDL::Doc.3 PDL::Doc::Perldl.3 \
	PDL::Graphics::PGPLOT.3 PDL::Graphics::IIS.3 PDL::Graphics::OpenGLQ.3 \
	PDL::Graphics::TriD::Rout.3 PDL::Graphics::TriD::MathGraph.3 \
	PDL::Graphics::TriD::Tk.3 PDL::Graphics::TriD::VRML.3 \
	PDL::Graphics::TriD.3 PDL::IO::FastRaw.3 PDL::IO::Misc.3 \
	PDL::IO::FlexRaw.3 PDL::IO::Pnm.3 PDL::IO::Browser.3 \
	PDL::IO::NDF.3 PDL::Opt::Simplex.3 PDL::ImageRGB.3 PDL::FFT.3 \
	PDL::Slatec.3 PDL::LinPred.3 PDL::Linear.3 PDL::Image2D.3 \
	PDL::ImageND.3 PDL::CallExt.3 PDL::Gaussian.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${MV} ${WRKSRC}/perldl.conf ${WRKSRC}/perldl.conf.tmp
	@${SED} -e s^%%LIBPATH%%^-L${X11BASE}/lib^g \
		< ${WRKSRC}/perldl.conf.tmp > ${WRKSRC}/perldl.conf.tmp2
	@${SED} -e s^%%INCPATH%%^-I${X11BASE}/include\ -I${X11BASE}/include/GL^g \
		< ${WRKSRC}/perldl.conf.tmp2 > ${WRKSRC}/perldl.conf
	@${RM} ${WRKSRC}/perldl.conf.tmp ${WRKSRC}/perldl.conf.tmp2
	for f in ${WRKSRC}/Basic/Core/*.PL ${WRKSRC}/Basic/Core/*.p \
			${WRKSRC}/Doc/Doc/*.PL ${WRKSRC}/Doc/Pod/*.PL \
			${WRKSRC}/Graphics/TriD/OpenGL/examples/clip \
			${WRKSRC}/t/*.t ; do \
		${MV} $$f $${f}.old ; \
		${SED} -e s!/usr/local/bin/perl!${PERL}! \
			< $${f}.old >$${f} ; \
	done

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}

post-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make test

.include <bsd.port.post.mk>
