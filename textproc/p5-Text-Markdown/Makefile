# New ports collection makefile for:	p5-Text-Markdown
# Date created:				20.Mar.2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Text-Markdown
PORTVERSION=	1.0.24
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Markdown Perl5 module

BUILD_DEPENDS=	${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
	${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
	${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	5.8.0+

MAN3=		Text::Markdown.3 \
		Text::MultiMarkdown.3

.include <bsd.port.mk>
