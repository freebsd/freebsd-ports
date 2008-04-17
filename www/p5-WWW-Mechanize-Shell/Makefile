# New Ports Collection Makefile for:	p5-WWW-Mechanize-Shell
# Date created:				2004-07-08
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Shell
PORTVERSION=	0.46
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An interactive shell for www/p5-WWW-Mechanize

BUILD_DEPENDS=	${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Term/Shell.pm:${PORTSDIR}/devel/p5-Term-Shell \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/WWW/Mechanize/FormFiller.pm:${PORTSDIR}/www/p5-WWW-Mechanize-FormFiller \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap \
		${SITE_PERL}/HTML/TokeParser/Simple.pm:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-HTML-Display>=0:${PORTSDIR}/www/p5-HTML-Display \
		p5-WWW-Mechanize>=1.20:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WWW::Mechanize::Shell.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README
EXAMPLES=	bin/banking.postbank.de.mech bin/hotmail.signup.mech bin/wwwshell.pl

post-install:
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Documentation installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
