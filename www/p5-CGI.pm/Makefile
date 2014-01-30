# $FreeBSD$

PORTNAME=	CGI.pm
PORTVERSION=	3.63
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKSTOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Simple Common Gateway Interface Class for Perl

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

EXAMPLES=	examples/caution.xbm examples/clickable_image.cgi \
		examples/cookie.cgi examples/crash.cgi examples/customize.cgi \
		examples/diff_upload.cgi examples/dna.small.gif \
		examples/file_upload.cgi examples/frameset.cgi \
		examples/index.html examples/internal_links.cgi \
		examples/javascript.cgi examples/make_links.pl \
		examples/monty.cgi examples/multiple_forms.cgi \
		examples/nph-clock.cgi examples/nph-multipart.cgi \
		examples/popup.cgi examples/save_state.cgi \
		examples/tryit.cgi examples/wilogo.gif

post-patch:
	@${REINPLACE_CMD} -e '/require 5\.6/d; /INSTALLDIRS/d' ${WRKSRC}/Makefile.PL

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
