# New ports collection makefile for:	p5-XML-RSS-LibXML
# Date created:		2006-01-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-LibXML
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	XML::RSS with XML::LibXML

BUILD_DEPENDS=	${SITE_PERL}/mach/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/mach/XML/LibXML/XPathContext.pm:${PORTSDIR}/textproc/p5-XML-LibXML-XPathContext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::LibXML.3 \
		XML::RSS::LibXML::Generator.3 \
		XML::RSS::LibXML::MagicElement.3 \
		XML::RSS::LibXML::Parser.3 \
		XML::RSS::LibXML::V10.3 \
	       	XML::RSS::LibXML::Format.3 \
	       	XML::RSS::LibXML::V09.3 \
	       	XML::RSS::LibXML::V20.3

.include <bsd.port.pre.mk>

.if (${PERL_LEVEL} < 500601)
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
