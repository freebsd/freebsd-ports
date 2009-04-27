# New ports collection makefile for:	textproc/p5-Template-Declare
# Date created:				23 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Declare
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perlish declarative templates

BUILD_DEPENDS=	${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/HTML/Lint.pm:${PORTSDIR}/www/p5-HTML-Lint \
		p5-Class-ISA>0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-String-BufferStack>=1.12:${PORTSDIR}/textproc/p5-String-BufferStack
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Template::Declare.3 \
	Template::Declare::Buffer.3 \
	Template::Declare::TagSet.3 \
	Template::Declare::TagSet::HTML.3 \
	Template::Declare::TagSet::RDF.3 \
	Template::Declare::TagSet::RDF::EM.3 \
	Template::Declare::TagSet::XUL.3 \
	Template::Declare::Tags.3

.include <bsd.port.mk>
