# New Ports Collection Makefile for:	p5-WWW-Mechanize-Shell
# Date created:				2004-07-08
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Shell
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An interactive shell for www/p5-WWW-Mechanize

BUILD_DEPENDS=	${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Term/Shell.pm:${PORTSDIR}/devel/p5-Term-Shell \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/WWW/Mechanize/FormFiller.pm:${PORTSDIR}/www/p5-WWW-Mechanize-FormFiller \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap \
		${SITE_PERL}/File/Modified.pm:${PORTSDIR}/devel/p5-File-Modified \
		${SITE_PERL}/HTML/TokeParser/Simple.pm:${PORTSDIR}/www/p5-HTML-TokeParser-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Display.3 \
	HTML::Display::Common.3 \
	HTML::Display::Debian.3 \
	HTML::Display::Dump.3 \
	HTML::Display::Galeon.3 \
	HTML::Display::Mozilla.3 \
	HTML::Display::OSX.3 \
	HTML::Display::OSX::Camino.3 \
	HTML::Display::OSX::Safari.3 \
	HTML::Display::Opera.3 \
	HTML::Display::Phoenix.3 \
	HTML::Display::TempFile.3 \
	HTML::Display::Win32.3 \
	HTML::Display::Win32::IE.3 \
	HTML::Display::Win32::OLE.3 \
	WWW::Mechanize::Shell.3

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port only support perl 5.6.1 or above
.endif

.include <bsd.port.post.mk>
