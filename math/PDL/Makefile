# Created by: Anton Berezin <tobez@plab.ku.dk>
# $FreeBSD$

PORTNAME=	PDL
PORTVERSION=	2.4.11
PORTREVISION=	3
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/${PORTNAME}:cpan \
		SF/pdl/PDL/${PORTVERSION}:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan,sf

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Data Language

BUILD_DEPENDS=	p5-Astro-FITS-Header>=0:${PORTSDIR}/astro/p5-Astro-FITS-Header \
		p5-Convert-UU>=0:${PORTSDIR}/converters/p5-Convert-UU \
		p5-File-Map>=0.47:${PORTSDIR}/devel/p5-File-Map \
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
OPTIONS_DEFAULT=	PGPLOT OPENGL FFTW F77

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGPLOT}
BUILD_DEPENDS+=	p5-PGPLOT>=0:${PORTSDIR}/graphics/p5-PGPLOT
.endif

.if ${PORT_OPTIONS:MPLPLOT}
LIB_DEPENDS+=	plplotd:${PORTSDIR}/math/plplot
.endif

.if ${PORT_OPTIONS:MOPENGL}
BUILD_DEPENDS+=	p5-OpenGL>=0.65:${PORTSDIR}/graphics/p5-OpenGL
RUN_DEPENDS+=	p5-OpenGL>=0.65:${PORTSDIR}/graphics/p5-OpenGL
USE_GL=		yes
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
.endif

.if ${PORT_OPTIONS:MF77}
BUILD_DEPENDS+=	p5-ExtUtils-F77>=0:${PORTSDIR}/lang/p5-ExtUtils-F77
.endif

.if ${PORT_OPTIONS:MFFTW}
LIB_DEPENDS+=	fftw:${PORTSDIR}/math/fftw
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
.endif

.if ${PORT_OPTIONS:MHDF}
LIB_DEPENDS+=	df:${PORTSDIR}/science/hdf
.endif

.if ${PORT_OPTIONS:MPROJ}
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
.endif

.if ${PORT_OPTIONS:MREADLINE}
RUN_DEPENDS+=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu
.else
RUN_DEPENDS+=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl
.endif

.if ${PORT_OPTIONS:MSINK}
RUN_DEPENDS+=	ppmtogif:${PORTSDIR}/graphics/netpbm \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		saoimage:${PORTSDIR}/astro/saoimage
.endif

post-patch:
	@${GREP} -lR '#!/usr/local/bin/perl' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|#!/usr/local/bin/perl|#!${PERL}|' -i ''
	@${GREP} -lR 'x86_64' ${WRKSRC}/ | ${XARGS} ${SED} -e 's|x86_64|amd64|g' -i ''
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' ${WRKSRC}/perldl.conf
	@${REINPLACE_CMD} -e "/POSIX_THREADS_LIBS/ s|undef|'${PTHREAD_LIBS}'|" \
		-e '/WITH_IO_BROWSER/ s|0|1|' -e '/WITH_DEVEL_REPL/ s|1|0|' ${WRKSRC}/perldl.conf
	@${REINPLACE_CMD} -e '/^#include <nan.h>/d' ${WRKSRC}/Basic/Math/mconf.h
	@${REINPLACE_CMD} -e '/^require PDL::Core::Dev;/d' ${WRKSRC}/IO/Browser/Makefile.PL

test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make test

# autogen plist
post-install:
	@(cd ${WRKSRC}; ${PERL} Doc/scantree.pl)
	@(cd ${WRKSRC}/blib/man3 ; \
	  ${FIND} *.3 | ${SED} "s,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/," \
		>> ${TMPPLIST} ; \
	  cd ${WRKSRC}/blib/man1 ; \
	  ${FIND} *.1 | ${SED} "s,^,man/man1/," >> ${TMPPLIST})
	@(${FIND} ${SITE_PERL}/${PERL_ARCH}/PDL* -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST} ; \
	  ${FIND} ${SITE_PERL}/${PERL_ARCH}/PDL* -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST} ; \
	  ${FIND} ${SITE_PERL}/${PERL_ARCH}/auto/PDL -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST} ; \
	  ${FIND} ${SITE_PERL}/${PERL_ARCH}/auto/PDL -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST})

.include <bsd.port.mk>
