# New ports collection makefile for:	shells/p5-Term-ShellUI
# Date created:				25 January 2007
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-ShellUI
PORTVERSION=	0.85
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term/BRONSON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A fully-featured shell-like command line environment

RUN_DEPENDS=	${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

PERL_CONFIGURE=	yes

SAMPLESDIR=	${WRKSRC}/examples

MAN3=	Term::ShellUI.3 \
	Text::Shellwords::Cursor.3

post-install:

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/RPC
	@${MKDIR} ${EXAMPLESDIR}/Term
	@${INSTALL_DATA} ${SAMPLESDIR}/RPC/Connection.pm	${EXAMPLESDIR}/RPC
	@${INSTALL_DATA} ${SAMPLESDIR}/Term/ExprUI.pm	${EXAMPLESDIR}/Term
	@${INSTALL_DATA} ${SAMPLESDIR}/README		${EXAMPLESDIR}
.for file in fileman-example psh synopsys synopsys-old tui-sample xmlexer
	    @${INSTALL_SCRIPT} ${SAMPLESDIR}/${file}	${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
