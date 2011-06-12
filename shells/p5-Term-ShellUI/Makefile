# New ports collection makefile for:	shells/p5-Term-ShellUI
# Date created:				25 January 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-ShellUI
PORTVERSION=	0.91
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A fully-featured shell-like command line environment

RUN_DEPENDS=	${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

PERL_CONFIGURE=	yes

MAN3=		Term::ShellUI.3 \
		Text::Shellwords::Cursor.3

post-install:

.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
.for file in fileman-example synopsis synopsis-big tui-sample
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
