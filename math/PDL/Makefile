# New ports collection makefile for:	PDL
# Date created:		08 February 1999
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	PDL
PORTVERSION=	2.3.4
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	PDL pdl

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Does not compile"

BUILD_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${PERL_SITELIBDIR}/ExtUtils/F77.pm:${PORTSDIR}/lang/p5-F77 \
		${PERL_SITELIBDIR}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${PERL_SITELIBDIR}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/PGPLOT.pm:${PORTSDIR}/graphics/pgperl \
		${PERL_SITELIBDIR}/Term/ReadLine/readline.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

USE_MESA=	yes
PERL_CONFIGURE=	yes
PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
SCRIPTS_ENV=	PERL=${PERL}

.if defined(KITCHEN_SINK)
LIB_DEPENDS+=	fftw.2:${PORTSDIR}/math/fftw \
		gsl.3:${PORTSDIR}/math/gsl
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

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	for f in ${WRKSRC}/Basic/Core/*.PL ${WRKSRC}/Basic/Core/*.p \
			${WRKSRC}/Doc/Doc/*.PL ${WRKSRC}/Doc/Pod/*.PL \
			${WRKSRC}/Graphics/TriD/OpenGL/examples/clip \
			${WRKSRC}/t/*.t ; do \
		${PERL} -pi -e "s!/usr/local/bin/perl!${PERL}!" $$f ; \
	done

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} make test

# autogen plist
post-install:
	@(cd ${WRKSRC}/blib/man3 ; \
	  ${FIND} *.3 | ${SED} "s,^,lib/perl5/${PERL_VERSION}/man/man3/," \
		>> ${TMPPLIST} ; \
	  cd ${WRKSRC}/blib/man1 ; \
	  ${FIND} *.1 | ${SED} "s,^,man/man1/," >> ${TMPPLIST})
	@(cd ${PERL_SITELIBDIR}/${PERL_ARCH} ; ${FIND} PDL* -type f | \
	  ${SED} "s,^,lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/," \
		>> ${TMPPLIST} ; \
	  ${FIND} PDL* -type d | sort -r | \
	${SED} "s,^,@dirrm lib/perl5/site_perl/${PERL_VERSION}/${PERL_ARCH}/," \
		>> ${TMPPLIST})

.include <bsd.port.post.mk>
