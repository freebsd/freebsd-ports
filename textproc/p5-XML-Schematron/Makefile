# New ports collection makefile for:	XML::Schematron
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	XML-Schematron
PORTVERSION=	0.98
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Perl implementation of the Schematron

BUILD_DEPENDS=	${SITE_PERL}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Schematron::Sablotron.3 \
		XML::Schematron::XPath.3 \
		XML::Schematron::LibXSLT.3 \
		XML::Schematron.3

.include <bsd.port.mk>
