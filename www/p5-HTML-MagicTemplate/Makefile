# New ports collection makefile for:	www/p5-HTML-MagicTemplate
# Date created:				October 18th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-MagicTemplate
PORTVERSION=	3.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	A Perl Module for using Text::MagicTemplate in a HTML env

BUILD_DEPENDS=	${SITE_PERL}/Text/MagicTemplate.pm:${PORTSDIR}/textproc/p5-Text-MagicTemplate \
		${SITE_PERL}/HTML/TableTiler.pm:${PORTSDIR}/www/p5-HTML-TableTiler \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		HTML::MagicTemplate.3

.include <bsd.port.mk>
