# New ports collection makefile for: p5-RDF-Simple
# Date created: July 12 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	RDF-Simple
PORTVERSION=	0.13
# PORTREVISION=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	Read and write RDF without complication

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RDF::Simple.3 RDF::Simple::Parser.3 RDF::Simple::Serialiser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars q{$$1};$$1/g' \
	${WRKSRC}/lib/RDF/Simple.pm ${WRKSRC}/lib/RDF/Simple/*.pm
.endif

.include <bsd.port.post.mk>
