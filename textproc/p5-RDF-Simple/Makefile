# New ports collection makefile for: p5-RDF-Simple
# Date created: July 12 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	RDF-Simple
PORTVERSION=	0.30
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read and write RDF without complication

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RDF::Simple.3 \
	RDF::Simple::NS.3 \
	RDF::Simple::Parser.3 \
	RDF::Simple::Serialiser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 #inherited from security/p5-Authen-SASL
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
