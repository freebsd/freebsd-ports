# $FreeBSD$

PORTNAME=	CGI.pm
PORTVERSION=	3.65
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKSTOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Common Gateway Interface Class for Perl

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

DEPRECATED=	Use www/p5-CGI instead
EXPIRATION_DATE=2019-04-30

CONFLICTS_INSTALL=	p5-CGI p5-CGI-Fast

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

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

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
