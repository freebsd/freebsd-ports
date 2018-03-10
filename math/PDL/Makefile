# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	PDL
PORTVERSION=	2.018
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Data Language

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Astro-FITS-Header>=0:astro/p5-Astro-FITS-Header \
		p5-Convert-UU>=0:converters/p5-Convert-UU \
		p5-File-Map>=0.57:devel/p5-File-Map \
		p5-Inline>=0.68:devel/p5-Inline \
		p5-Inline-C>=0.62:devel/p5-Inline-C \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Compile>=0.23:devel/p5-Module-Compile
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Devel-CheckLib>=1.01:devel/p5-Devel-CheckLib
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

PORTSCOUT=	limit:^[0-9]\.[0-9][0-9]+[0-9\.]*$$

USES=		gmake perl5
USE_PERL5=	configure
MAKE_ENV=	PERL5LIB=${WRKSRC}/blib/lib
PLIST_FILES=	bin/pdl bin/pdl2 bin/pdldoc bin/perldl bin/pptemplate \
		${SITE_ARCH_REL}/Inline/Pdlpp.pm \
		${SITE_ARCH_REL}/Inline/MakePdlppInstallable.pm
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PGPLOT PLPLOT OPENGL GD FFTW GSL HDF PROJ F77 READLINE SINK
OPTIONS_DEFAULT=PGPLOT FFTW F77

# graphics/p5-OpenGL require manual building
.if empty(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	OPENGL
.endif

PGPLOT_DESC=	Enable PDL::Graphics::PGPLOT
PLPLOT_DESC=	Enable PDL::Graphics::PLplot
OPENGL_DESC=	Enable PDL::Graphics::TriD and OpenGL
GD_DESC=	Enable PDL::IO::GD
FFTW_DESC=	Enable PDL::FFTW
GSL_DESC=	Enable PDL::GSL interface
HDF_DESC=	Enable PDL::IO::HDF interface
PROJ_DESC=	Enable PDL::GIS::Proj interface
F77_DESC=	Enable PDL::Minuit and PDL::Slatec
READLINE_DESC=	Use GNU readline
SINK_DESC=	Include PDL kitchen sink

PGPLOT_BUILD_DEPENDS=	p5-PGPLOT>=0:graphics/p5-PGPLOT
PLPLOT_LIB_DEPENDS=	libplplotd.so:math/plplot
OPENGL_BUILD_DEPENDS=	p5-OpenGL>=0.65:graphics/p5-OpenGL
OPENGL_RUN_DEPENDS:=	${OPENGL_BUILD_DEPENDS}
OPENGL_USE=		gl=yes
GD_LIB_DEPENDS=		libgd.so:graphics/gd
F77_BUILD_DEPENDS=	p5-ExtUtils-F77>=0:lang/p5-ExtUtils-F77
FFTW_LIB_DEPENDS=	libfftw.so:math/fftw
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
HDF_LIB_DEPENDS=	libdf.so:science/hdf
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj
READLINE_RUN_DEPENDS=	p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu
READLINE_RUN_DEPENDS_OFF=	p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl
SINK_RUN_DEPENDS=	ppmtogif:graphics/netpbm \
			mpeg_encode:multimedia/mpeg_encode \
			saoimage:astro/saoimage

post-patch:
	@${GREP} -lR '#!/.*bin/perl' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|#!/.*bin/perl|#!${PERL}|' -i ''
	@${GREP} -lR 'x86_64' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|x86_64|amd64|g' -i ''
	@${REINPLACE_CMD} -e "/POSIX_THREADS_LIBS/ s|undef|'-lpthread'|" \
		${WRKSRC}/perldl.conf

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL -name '*.so' \
		| ${XARGS} ${STRIP_CMD}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pdl
# autogen plist
	@(cd ${WRKSRC}; ${PERL} -Iblib/lib -Iblib/arch Doc/scantree.pl)
	@(cd ${WRKSRC}/blib/man3 ; \
	  ${FIND} *.3 | ${SED} "s,^,${MAN3PREFIX}/man/man3/,;s/3$$/3.gz/" \
		>> ${TMPPLIST} ; \
	  cd ${WRKSRC}/blib/man1 ; \
	  ${FIND} *.1 | ${SED} "s,^,${MAN1PREFIX}/man/man1/,;s/1$$/1.gz/" \
		>> ${TMPPLIST})
	@(${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/PDL* -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST} ; \
	  ${FIND} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDL -type f \
		-name "[A-Z]*" | ${SED} "s,^${STAGEDIR}${PREFIX}/,," \
		>> ${TMPPLIST})

.include <bsd.port.mk>
