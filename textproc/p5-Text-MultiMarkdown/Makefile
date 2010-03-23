# New ports collection makefile for:	p5-Text-MultiMarkdown
# Date created:				23 Oct, 2009
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-MultiMarkdown
PORTVERSION=	1.000033
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Convert MultiMarkdown syntax to (X)HTML

BUILD_DEPENDS=	\
	${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
	${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
	p5-Text-Markdown>=1.0.26:${PORTSDIR}/textproc/p5-Text-Markdown
RUN_DEPENDS=	\
	p5-Text-Markdown>=1.0.26:${PORTSDIR}/textproc/p5-Text-Markdown

PERL_CONFIGURE=	yes

MAN1=		MultiMarkdown.pl.1
MAN3=		Text::MultiMarkdown.3

.include <bsd.port.mk>
