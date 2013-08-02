# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Shell
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CORION
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An interactive shell for www/p5-WWW-Mechanize

BUILD_DEPENDS=	p5-HTML-Display>=0:${PORTSDIR}/www/p5-HTML-Display \
		p5-HTML-TokeParser-Simple>=2:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-Hook-LexWrap>=0.2:${PORTSDIR}/devel/p5-Hook-LexWrap \
		p5-Term-Shell>=0.02:${PORTSDIR}/devel/p5-Term-Shell \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.2:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-FormFiller>=0.05:${PORTSDIR}/www/p5-WWW-Mechanize-FormFiller \
		p5-libwww>=5.69:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Mechanize::Shell.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README
.endif

.if !defined(NOPORTEXAMPLES)
EXAMPLES=	bin/banking.postbank.de.mech bin/hotmail.signup.mech bin/wwwshell.pl
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Documentation installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
