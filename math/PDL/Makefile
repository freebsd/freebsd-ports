# New ports collection makefile for:	PDL
# Date created:		08 February 1999
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	PDL
PORTVERSION=	2.4.7
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/${PORTNAME}:cpan \
		SF/pdl/PDL/${PORTVERSION}:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan,sf

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Data Language

BUILD_DEPENDS=	p5-Convert-UU>=0:${PORTSDIR}/converters/p5-Convert-UU \
		p5-Inline>=0.43:${PORTSDIR}/devel/p5-Inline \
		p5-Astro-FITS-Header>=0:${PORTSDIR}/astro/p5-Astro-FITS-Header 
RUN_DEPENDS=	p5-Convert-UU>=0:${PORTSDIR}/converters/p5-Convert-UU \
		p5-Inline>=0.43:${PORTSDIR}/devel/p5-Inline \
		p5-Astro-FITS-Header>=0:${PORTSDIR}/astro/p5-Astro-FITS-Header 

PERL_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	PERL5LIB=${WRKSRC}/blib/lib
PLIST_DIRS=	${SITE_PERL_REL}/${PERL_ARCH}/Inline
PLIST_FILES=	bin/pdl bin/pdldoc bin/perldl bin/pptemplate \
		${SITE_PERL_REL}/${PERL_ARCH}/Inline/Pdlpp.pm \
		${SITE_PERL_REL}/${PERL_ARCH}/Inline/MakePdlppInstallable.pm
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	PGPLOT "Enable PDL::Graphics::PGPLOT" on \
		PLPLOT "Enable PDL::Graphics::PLplot" off \
		GL "Enable PDL::Graphics::TriD and OpenGL" on \
		GD "Enable PDL::IO::GD" off \
		FFTW "Enable PDL::FFTW" on \
		GSL "Enable PDL::GSL interface" off \
		HDF "Enable PDL::IO::HDF interface" off \
		PROJ "Enable PDL::GIS::Proj interface" off \
		F77 "Enable PDL::Minuit and PDL::Slatec" on \
		READLINE "Use GNU readline" off \
		SINK "Include PDL kitchen sink" off

.include <bsd.port.options.mk>

.if defined(WITH_PGPLOT)
BUILD_DEPENDS+=	p5-PGPLOT>=0:${PORTSDIR}/graphics/p5-PGPLOT
.endif

.if defined(WITH_PLPLOT)
LIB_DEPENDS+=	plplotd.10:${PORTSDIR}/math/plplot
.endif

.if defined(WITH_GL)
# Please uncomment this two lines after updating OpenGL to 0.60+
#BUILD_DEPENDS+=	p5-OpenGL>=0.60:${PORTSDIR}/graphics/p5-OpenGL
#RUN_DEPENDS+=	p5-OpenGL>=0.60:${PORTSDIR}/graphics/p5-OpenGL
USE_GL=		yes
.endif

.if defined(WITH_GD)
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
.endif

.if defined(WITH_F77)
BUILD_DEPENDS+=	p5-ExtUtils-F77>=0:${PORTSDIR}/lang/p5-F77 
.endif

.if defined(WITH_FFTW)
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw
.endif

.if defined(WITH_GSL)
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
.endif

.if defined(WITH_HDF)
LIB_DEPENDS+=	df:${PORTSDIR}/science/hdf
.endif

.if defined(WITH_PROJ)
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
.endif

.if defined(WITH_READLINE)
RUN_DEPENDS+=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu 
.else
RUN_DEPENDS+=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl 
.endif

.if defined(WITH_SINK)
RUN_DEPENDS+=	ppmtogif:${PORTSDIR}/graphics/netpbm \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		saoimage:${PORTSDIR}/astro/saoimage
.endif

post-patch:
	@${GREP} -lR "/usr/local/bin/perl" ${WRKSRC} | ${XARGS} \
		${PERL} -pi -e "s!/usr/local/bin/perl!${PERL}!"
	@${GREP} -lR "x86_64" ${WRKSRC} | ${XARGS} \
	    	${PERL} -pi -e "s!x86_64!amd64!"

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
