# New ports collection makefile for:	textproc/p5-XML-DOM-XPath
# Date created:				8 September 2005
# Whom:					Mauricio Herrera Cuadra <mauricio@arareko.net>
#
# $FreeBSD$
#

PORTNAME=	XML-DOM-XPath
PORTVERSION=	0.14
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mauricio@arareko.net
COMMENT=	Adds XPath support to XML::DOM, using XML::XPath engine

RUN_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-XML-XPathEngine>=0:${PORTSDIR}/textproc/p5-XML-XPathEngine

PERL_CONFIGURE=	yes

MAN3=	XML::DOM::XPath.3

.include <bsd.port.mk>
