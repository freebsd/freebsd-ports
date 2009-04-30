# New ports collection makefile for:	p5-XML-XPathEngine
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XPathEngine
PORTVERSION=	0.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A re-usable XPath engine for DOM-like trees

PERL_CONFIGURE=	yes

MAN3=		XML::XPathEngine.3 XML::XPathEngine::Boolean.3 \
		XML::XPathEngine::Literal.3 XML::XPathEngine::NodeSet.3 \
		XML::XPathEngine::Number.3

# For errors like
# Bareword "XML::XPathEngine::Step::..." not allowed while "strict subs" in use at ...
post-patch:
	${REINPLACE_CMD} -Ee 's,(use strict;),\1 no strict "subs";,' ${WRKSRC}/lib/XML/XPathEngine.pm
	${RM} ${WRKSRC}/lib/XML/XPathEngine.pm.bak

.include <bsd.port.mk>
