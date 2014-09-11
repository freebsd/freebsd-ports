# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	PDL
PORTVERSION=	2.007
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/${PORTNAME} SF/pdl/PDL_2013/PDL-${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Data Language

BUILD_DEPENDS=	p5-Astro-FITS-Header>=0:${PORTSDIR}/astro/p5-Astro-FITS-Header \
		p5-Convert-UU>=0:${PORTSDIR}/converters/p5-Convert-UU \
		p5-File-Map>=0.47:${PORTSDIR}/devel/p5-File-Map \
		p5-Module-Compile>=0.23:${PORTSDIR}/devel/p5-Module-Compile \
		p5-Inline>=0.43:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake perl5
USE_PERL5=	configure
MAKE_ENV=	PERL5LIB=${WRKSRC}/blib/lib
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/Inline
PLIST_FILES=	bin/pdl bin/pdldoc bin/perldl bin/pptemplate \
		${SITE_PERL_REL}/${PERL_ARCH}/Inline/Pdlpp.pm \
		${SITE_PERL_REL}/${PERL_ARCH}/Inline/MakePdlppInstallable.pm
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PGPLOT PLPLOT OPENGL GD FFTW GSL HDF PROJ F77 READLINE SINK
OPTIONS_DEFAULT=	PGPLOT FFTW F77

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

PGPLOT_BUILD_DEPENDS=	p5-PGPLOT>=0:${PORTSDIR}/graphics/p5-PGPLOT
PLPLOT_LIB_DEPENDS=	libplplotd.so:${PORTSDIR}/math/plplot
OPENGL_BUILD_DEPENDS=	p5-OpenGL>=0.65:${PORTSDIR}/graphics/p5-OpenGL
OPENGL_RUN_DEPENDS:=	${OPENGL_BUILD_DEPENDS}
OPENGL_USE=	gl=yes
GD_LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd
F77_BUILD_DEPENDS=	p5-ExtUtils-F77>=0:${PORTSDIR}/lang/p5-ExtUtils-F77
FFTW_LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw
GSL_LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl
HDF_LIB_DEPENDS=	libdf.so:${PORTSDIR}/science/hdf
PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj
READLINE_RUN_DEPENDS=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu
READLINE_RUN_DEPENDS_OFF=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl
SINK_RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm \
			mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
			saoimage:${PORTSDIR}/astro/saoimage

post-patch:
	@${GREP} -lR '#!/.*bin/perl' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|#!/.*bin/perl|#!${PERL}|' -i ''
	@${GREP} -lR 'x86_64' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|x86_64|amd64|g' -i ''
	@${REINPLACE_CMD} -e "/POSIX_THREADS_LIBS/ s|undef|'${PTHREAD_LIBS}'|" \
		${WRKSRC}/perldl.conf

test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make test

# autogen plist
post-install:
	@(cd ${WRKSRC}; ${PERL} -Iblib/lib -Iblib/arch Doc/scantree.pl)
	@(cd ${WRKSRC}/blib/man3 ; \
	  ${FIND} *.3 | ${SED} "s,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,;s/3$$/3.gz/" \
		>> ${TMPPLIST} ; \
	  cd ${WRKSRC}/blib/man1 ; \
	  ${FIND} *.1 | ${SED} "s,^,man/man1/,;s/1$$/1.gz/" >> ${TMPPLIST})
	@(${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/PDL* -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST} ; \
	  ${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/PDL -type f ! -name '*.bs' | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST} ; \
	  ${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/PDL* -type d | ${SORT} -r | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,@dirrm ," >> ${TMPPLIST} ; \
	  ${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/PDL -type d | ${SORT} -r | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,@dirrm ," >> ${TMPPLIST})

.include <bsd.port.mk>
