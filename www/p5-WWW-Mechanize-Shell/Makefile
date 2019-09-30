# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Shell
PORTVERSION=	0.58
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CORION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interactive shell for www/p5-WWW-Mechanize

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Display>=0:www/p5-HTML-Display \
		p5-HTML-TokeParser-Simple>=2.0:www/p5-HTML-TokeParser-Simple \
		p5-Hook-LexWrap>=0.20:devel/p5-Hook-LexWrap \
		p5-Term-Shell>=0.02:devel/p5-Term-Shell \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=1.20:www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-FormFiller>=0.05:www/p5-WWW-Mechanize-FormFiller \
		p5-libwww>=5.69:www/p5-libwww
TEST_DEPENDS=	p5-CGI>=0:www/p5-CGI \
		p5-Test-HTTP-LocalServer>=0:www/p5-Test-HTTP-LocalServer \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	banking.postbank.de.mech hotmail.signup.mech wwwshell.pl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/bin && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
