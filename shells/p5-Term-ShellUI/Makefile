# New ports collection makefile for:	shells/p5-Term-ShellUI
# Date created:				25 January 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-ShellUI
PORTVERSION=	0.92
CATEGORIES=	shells perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A fully-featured shell-like command line environment

BUILD_DEPENDS=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl
RUN_DEPENDS=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl

PERL_CONFIGURE=	yes

MAN3=		Term::ShellUI.3 \
		Text::Shellwords::Cursor.3

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
	${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	cd ${WRKSRC}/examples/ && ${INSTALL_SCRIPT} \
		fileman-example synopsis synopsis-big tui-sample ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
