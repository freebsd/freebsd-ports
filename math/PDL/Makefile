# ex:ts=8
# New ports collection makefile for:	PDL
# Date created:		08 February 1999
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	PDL
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:cpan \
			${PORTNAME:L}/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Data Language

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${SITE_PERL}/ExtUtils/F77.pm:${PORTSDIR}/lang/p5-F77 \
		${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${SITE_PERL}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter \
		${SITE_PERL}/Astro/FITS/Header.pm:${PORTSDIR}/astro/p5-Astro-FITS-Header
LIB_DEPENDS=	plplotd.10:${PORTSDIR}/math/plplot \
		fftw.2:${PORTSDIR}/math/fftw \
		gsl.7:${PORTSDIR}/math/gsl
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${SITE_PERL}/Term/ReadLine/readline.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

USE_GL=		yes
PERL_CONFIGURE=	yes
PLIST_DIRS=	${SITE_PERL:S,^${PREFIX}/,,}/${PERL_ARCH}/Inline
PLIST_FILES=	bin/pdldoc bin/perldl bin/pptemplate \
		${SITE_PERL:S,^${PREFIX}/,,}/${PERL_ARCH}/Inline/Pdlpp.pm \
		${SITE_PERL:S,^${PREFIX}/,,}/${PERL_ARCH}/Inline/MakePdlppInstallable.pm

.if defined(KITCHEN_SINK)
RUN_DEPENDS+=	ppmtogif:${PORTSDIR}/graphics/netpbm \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
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

.if ${PERL_LEVEL} < 500601
IGNORE=	Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif # ${PERL_LEVEL} < 500601

post-patch:
	@${GREP} -lR "/usr/local/bin/perl" ${WRKSRC} | ${XARGS} \
		${PERL} -pi -e "s!/usr/local/bin/perl!${PERL}!"

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make test

# autogen plist
post-install:
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

.include <bsd.port.post.mk>
