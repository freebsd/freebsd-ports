# New ports collection makefile for:	Lingua::EN::Summarize
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Summarize
PORTVERSION=	0.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	A simple tool for summarizing bodies of English text

BUILD_DEPENDS=	${SITE_PERL}/HTML/Summary.pm:${PORTSDIR}/www/p5-HTML-Summary
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Filters.3 \
	Lingua::EN::Summarize.3

.include <bsd.port.mk>
