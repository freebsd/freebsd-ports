# New ports collection makefile for:	p5-libxml
# Date created:		13 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTNAME=	libxml-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of Perl5 modules for working with XML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Data::Grove.3 Data::Grove::Parent.3 Data::Grove::Visitor.3 \
		XML::ESISParser.3 XML::Handler::CanonXMLWriter.3 \
		XML::Handler::Sample.3 XML::Handler::Subs.3 \
		XML::Handler::XMLWriter.3 XML::Parser::PerlSAX.3 \
		XML::PatAct::ActionTempl.3 XML::PatAct::Amsterdam.3 \
		XML::PatAct::MatchName.3 XML::PatAct::PatternTempl.3 \
		XML::PatAct::ToObjects.3 XML::Perl2SAX.3 XML::SAX2Perl.3


.include <bsd.port.mk>
