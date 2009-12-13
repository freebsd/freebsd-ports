# New ports collection makefile for:    p5-HTML-Scrubber
# Date created:				31 Oct 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-Scrubber
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for scrubbing/sanitizing html

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		HTML::Scrubber.3

.include <bsd.port.mk>
