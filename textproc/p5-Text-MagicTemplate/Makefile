# New ports collection makefile for:	textproc/p5-Text-MagicTemplate
# Date created:				October 18th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-MagicTemplate
PORTVERSION=	3.44
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Perl Module with magic merger of runtime values with templates

BUILD_DEPENDS=	${SITE_PERL}/HTML/TableTiler.pm:${PORTSDIR}/www/p5-HTML-TableTiler \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm

PERL_CONFIGURE=	YES

MAN3=		Text::MagicTemplate.3 \
		Bundle::Text::MagicTemplate.3 \
		HTML::MagicTemplate.3 \
		Text::MagicTemplate::Zone.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
