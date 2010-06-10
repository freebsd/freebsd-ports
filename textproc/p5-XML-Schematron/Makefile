# New ports collection makefile for:	XML::Schematron
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	XML-Schematron
PORTVERSION=	1.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the Schematron

RUN_DEPENDS=	${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml

PERL_CONFIGURE=	yes

MAN3=	XML::Schematron::XPath.3 \
		XML::Schematron::LibXSLT.3 \
		XML::Schematron.3

.include <bsd.port.mk>
