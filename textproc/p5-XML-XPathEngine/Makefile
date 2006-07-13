# New ports collection makefile for:	p5-XML-XPathEngine
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XPathEngine
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A re-usable XPath engine for DOM-like trees

PERL_CONFIGURE=	yes

MAN3=		XML::XPathEngine.3 XML::XPathEngine::Boolean.3 \
		XML::XPathEngine::Literal.3 XML::XPathEngine::NodeSet.3 \
		XML::XPathEngine::Number.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
