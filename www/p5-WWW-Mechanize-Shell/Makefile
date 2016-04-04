# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Shell
PORTVERSION=	0.55
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CORION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interactive shell for www/p5-WWW-Mechanize

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Display>=0:www/p5-HTML-Display \
		p5-HTML-TokeParser-Simple>=2:www/p5-HTML-TokeParser-Simple \
		p5-Hook-LexWrap>=0.2:devel/p5-Hook-LexWrap \
		p5-Term-Shell>=0.02:devel/p5-Term-Shell \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=1.2:www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-FormFiller>=0.05:www/p5-WWW-Mechanize-FormFiller \
		p5-libwww>=5.69:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure

PORTEXAMPLES=	banking.postbank.de.mech hotmail.signup.mech wwwshell.pl

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/bin && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})
	@${ECHO_MSG} "===> Documentation installed in ${EXAMPLESDIR}."

.include <bsd.port.mk>
